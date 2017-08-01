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

#include "rest.h"

const long CURLOPT_DISABLE=0;
const long CURLOPT_ENABLE=1;
const int  BUFFER_SZ=120;

char* HTTP="http://";
char* HTTPS="https://";

CURLcode httpRequest(Connection c, char* res, char* data, Operation op) {
  CURLcode rcode;
  c = bind(c, res);
  switch(op) {
      case GET:
         curl_easy_setopt(c.connection, CURLOPT_HTTPGET, CURLOPT_ENABLE);
         break;
      case POST:
         curl_easy_setopt(c.connection, CURLOPT_CUSTOMREQUEST, "POST");
         curl_easy_setopt(c.connection, CURLOPT_POSTFIELDS, data);
         break;
      case PUT:
         curl_easy_setopt(c.connection, CURLOPT_CUSTOMREQUEST, "PUT");
         curl_easy_setopt(c.connection, CURLOPT_POSTFIELDS, data);
         break;
      case DELETE:
         curl_easy_setopt(c.connection, CURLOPT_CUSTOMREQUEST, "DELETE");
         break;
      default:
         NULL;
  }
  rcode = curl_easy_perform(c.connection);
  return rcode;
}

Connection bind(Connection c, char* res) {
  char* url = (char*) malloc(sizeof(char) * BUFFER_SZ);
  sprintf(url,"%s%s:%s%s%s", c.protocol, c.host.ip, c.host.port, c.host.service, res);
  curl_easy_setopt(c.connection, CURLOPT_URL, url);

  return c;
}

Connection openConnection(Host h, User u) {
  CURL *curl;
  char* userpwd = (char*) malloc(sizeof(char) * BUFFER_SZ);
  struct curl_slist *headers = NULL;
  curl = curl_easy_init();

  sprintf(userpwd,"%s:%s", u.name, u.passwd);

  headers = curl_slist_append(headers, "Accept: application/json");
  headers = curl_slist_append(headers, "Content-Type: application/json");
  headers = curl_slist_append(headers, "charsets: utf-8");

  curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
  curl_easy_setopt(curl, CURLOPT_HTTPAUTH, CURLAUTH_BASIC);
  curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, CURLOPT_DISABLE);
  curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, CURLOPT_DISABLE);
  curl_easy_setopt(curl, CURLOPT_USERPWD, userpwd);

  Connection conn = {.connection = curl, .host = h, .user = u, .protocol = HTTPS};

  return conn; 
}

void closeConnection(Connection c) {
  curl_easy_cleanup(c.connection);
  //curl_slist_free_all(headers);
}
