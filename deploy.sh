#!/bin/bash

chmod +x htdocs/*.cgi

yum install -y perl perl-CGI

make clean && make
