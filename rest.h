/***************************************************************************
 * Copyright (C) 2017, Michael Jastad, <michael.jastad@nutanix.com>, et al.
 *
 * This software is licensed as described in the file COPYING, which
 * you should have received as part of this distribution. 
 *
 * You may opt to use, copy, modify, merge, publish, distribute copies of the 
 * Software, and permit persons to whom the Software is furnished to do so, 
 * under the terms of the COPYING file.
 *
 * This software is distributed on an "AS IS" basis, WITHOUT WARRANTY OF ANY
 * KIND, either express or implied.
 *
 ***************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>

typedef struct {
 char* ip;
 char* port;
 char* service; 
} Host;

typedef struct {
  char* name;
  char* passwd;
} User;

typedef struct {
  CURL* connection;
  Host host;
  User user;
  char* protocol;
} Connection;

typedef enum {
  GET,
  PUT,
  POST,
  DELETE
} Operation;

CURLcode httpRequest(Connection c, char* res, char* data, Operation op);

Connection openConnection(Host h, User u);
Connection bind(Connection c, char* res);

void closeConnection(Connection c);

