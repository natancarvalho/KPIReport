# KPIReport

The main.cpp calls the functions cgiPage() to create a CGI with the web page and pythonAPI() to create a dashboard using Plotly both in localhost 
but in different ports.

To run the code is necessary install and confiure the Apache Server to be able a execute CGI files on the diretory: "/usr/lib/cgi-bin".

After build the code in CLion, run the command line: "sudo cmake --install ~/OptimumG/Dev/KPIReport/cmake-build-debug" to install the excutable 
on the diretory mencioned before.

For last, access the page: "http://localhost/cgi-bin/KPIReport.cgi". 

main.cpp - this file is responsible to call the auxiliars functions and methods to read a CSV, communicate with SQL database, innitialize Python API, ...

__main__.py - scrip in Python that create a dashbard using Plotly with the data required on the C++ application.

/include/
  cars.h - declaration of the class car.

  constants.h - declarition of constants that will be use in the code.

  events.h - declaration of the class events.

  functions.cpp - implementantion of any auxiliar function thaht will be use in the code.

  functions.h - declaration of any auxiliar function that will be use in the code.

  queries.h - declaration of any query that will be use in the code.

