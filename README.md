# KPIReport

The main.cpp calls the functions cgiPage() to create a CGI with the web page and pythonAPI() to create a dashboard using Plotly both in localhost 
but in different ports.

To run the code is necessary install and confiure the Apache Server to be able a execute CGI files on the diretory: "/usr/lib/cgi-bin".

After build the code in CLion, run the command line: "sudo cmake --install ~/OptimumG/Dev/KPIReport/cmake-build-debug" to install the excutable 
on the diretory mencioned before.

For last, access the page: "http://localhost/cgi-bin/KPIReport.cgi".
