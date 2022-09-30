//
// Created by natan on 21/09/22.
//
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <python3.10/Python.h>
#include <string>
#include <vector>

#include "mysql_connection.h"
#include "functions.h"
#include "queries.h"

#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>


using namespace sql;
using namespace std;

void cgiPage(){
    cout << "Content-type:text/html\r\n\r\n";
    cout << "<html>\n";
    cout << "<head>\n";
    cout << "<title>Hello World - First CGI Program</title>\n";
    cout << "</head>\n";
    cout << "<body>\n";
    cout << "<h2>Hello World! This is my first CGI program</h2>\n";
    cout <<"<table border=\"1\">";
    cout <<"              <tr>";
    cout <<"              <td>Nome</td>";
    cout <<"              <td>Idade</td>";
    cout <<"              <td>Profissão</td>";
    cout <<"              </tr>";
    cout <<"                <tr>";
    cout <<"                <td>Ted</td>";
    cout <<"                <td>22</td>";
    cout <<"                        <td>Estudante</td>";
    cout <<"                        </tr>";
    cout <<"                         <tr>";
    cout <<"                          <td>Ralf</td>";
    cout <<"                         <td>26</td>";
    cout <<"                                 <td>Designer</td>";
    cout <<"                                 </tr>";
    cout <<"                                   </table>";
    cout << "</body>\n";
    cout << "</html>\n";
    cout << endl;

//    FILE* fp;
//    fp = fopen("/home/natan/OptimumG/Dev/KPIReport/cmake-build-debug/home.txt", "rt");
//    char *result;
//    char Linha[100];
//    int i = 1;
//    while (!feof(fp))
//    {
//        // Lê uma linha (inclusive com o '\n')
//        result = fgets(Linha, 100, fp);  // o 'fgets' lê até 99 caracteres ou até o '\n'
//        if (result)  // Se foi possível ler
//            cout << Linha;
//        i++;
//    }
//    fclose(fp);
//    //cout << fp;
//    cout << endl;
}

void createDB() {

    cout << "Running 'SELECT 'Hello World!' AS _message'..." << endl;

    cout << endl;
    cout << "Let's have MySQL count from 10 to 1..." << endl;

    try {
        sql::Driver *driver;
        sql::Connection *con;
        sql::Statement *stmt;
        sql::ResultSet *res;
        sql::PreparedStatement *pstmt;

        /* Create a connection */
        driver = get_driver_instance();
        con = driver->connect(DB_SERVER, DB_LOGIN, DB_PASSWORD);
        /* Connect to the MySQL test database */
        con->setSchema("dadospneus");

//        stmt = con->createStatement();
//        stmt->execute("DROP TABLE IF EXISTS test");
//        stmt->execute("CREATE TABLE test(id INT)");
//        delete stmt;
//
//        /* '?' is the supported placeholder syntax */
//        pstmt = con->prepareStatement("INSERT INTO test(id) VALUES (?)");
//        for (int i = 1; i <= 10; i++) {
//            pstmt->setInt(1, i);
//            pstmt->executeUpdate();
//        }
//        delete pstmt;

        /* Select in ascending order */
        pstmt = con->prepareStatement("SELECT id FROM test ORDER BY id ASC");
        res = pstmt->executeQuery();

        /* Fetch in reverse = descending order! */
        res->afterLast();
        while (res->previous())
            cout << "\t... MySQL counts: " << res->getInt("id") << endl;
        delete res;

        delete pstmt;
        delete con;

    } catch (sql::SQLException &e) {
        cout << "# ERR: SQLException in " << __FILE__;
        cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << endl;
        cout << "# ERR: " << e.what();
        cout << " (MySQL error code: " << e.getErrorCode();
        cout << ", SQLState: " << e.getSQLState() << " )" << endl;
    }

    cout << endl;
}

void pythonAPI(){
    Py_Initialize();
    //Run_SimpleString("import plotly.express as px\n"
    //                   "fig = px.scatter(x=[0, 1, 2, 3, 4], y=[0, 1, 4, 9, 16])\n"
    //                   "fig.show()";
    FILE* fp;
    fp = fopen("/home/natan/OptimumG/Learning/DBConnect/cmake-build-debug/teste.py", "r");
    PyRun_AnyFile(fp, " ");
    Py_Finalize();
    fclose(fp);
}

void connectDB(){
    sql::Driver *driver;
    sql::Connection *con;
    sql::Statement *stmt;
    sql::ResultSet  *res;

    /* Create a connection */
    driver = get_driver_instance();
    con = driver->connect("tcp://127.0.0.1:3306", "root", "C@rvalhoBD");
    /* Connect to the MySQL test database */
    con->setSchema("dadospneus");
// ...
    stmt = con->createStatement();
// ...
    ofstream out("../csv/dados.csv");
    res = stmt->executeQuery("SELECT id, Piloto, Pneu FROM dadospneus.treino1 ORDER BY id ASC");
    out << "id,Piloto,Pneu" << endl;
//    cout << "id,Piloto,Pneu" << endl;
    while (res->next()) {
//      You can use either numeric offsets...
        out << res->getInt(1) << "," << res->getString("Piloto") << "," <<res->getString("Pneu") << endl;
//        cout << res->getInt(1) << "," << res->getString("Piloto") << "," <<res->getString("Pneu") << endl; // getInt(1) returns the first column
//      ... or column names for accessing results.
//      The latter is recommended.
//      cout << ", label = '" << res->getString("Pneu") << "'" << endl;
    }
    out.close();

    delete res;
    delete stmt;
    delete con;
}

vector <string> read_csv_header(const char* pathCSV){
    FILE* fp;
    fp = fopen(pathCSV, "rt");
    char *result;
    char Linha[100];
    int i = 1;
    vector <string> linha_csv;

    while (i<7/*!feof(fp)*/)
    {
        // Lê uma linha (inclusive com o '\n')
        result = fgets(Linha, 100, fp);  // o 'fgets' lê até 99 caracteres ou até o '\n'
        if (result)  // Se foi possível ler
            linha_csv.insert(linha_csv.end(), result);
        i++;
    }

    fclose(fp);
    return linha_csv;
    //cout << fp;
    //cout << endl;
}

string read_csv_data(const char* pathCSV){
    FILE* fp;
    fp = fopen(pathCSV, "rt");
    char *result;
    char Linha[100];
    int i = 1;
    string linha_csv;

    while (!feof(fp)){
        if (i > 6) {
            // Lê uma linha (inclusive com o '\n')
            result = fgets(Linha, 100, fp);  // o 'fgets' lê até 99 caracteres ou até o '\n'
            if (result)  // Se foi possível ler
                linha_csv += Linha;
            i++;
        }
        else {
            i++;
        }
    }

    fclose(fp);
    return linha_csv;
}
