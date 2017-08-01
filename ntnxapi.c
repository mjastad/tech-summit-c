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

/* <DESC>
 * NTNX HTTP REST API/Client
 * </DESC>
 */

#include "ntnxres.h" 
#include "rest.h" 

void NTNXDeleteVirtualMachines(Connection con, char* data) {
  CURLcode retcode;
  Operation op;

  retcode = httpRequest(con, RESOURCE_VM, data, op=DELETE);

  if(retcode != CURLE_OK)
      fprintf(stderr, "curl failed: %s\n", curl_easy_strerror(retcode));
}

void NTNXPwrOFFVirtualMachine(Connection con, char* data) {
  CURLcode retcode;
  Operation op;

  retcode = httpRequest(con, RESOURCE_VM_PWR_STATE, data, op=POST);

  if(retcode != CURLE_OK)
      fprintf(stderr, "curl failed: %s\n", curl_easy_strerror(retcode));
}

void NTNXPwrONVirtualMachine(Connection con, char* data) {
  CURLcode retcode;
  Operation op;

  retcode = httpRequest(con, RESOURCE_VM_PWR_STATE, data, op=POST);

  if(retcode != CURLE_OK)
      fprintf(stderr, "curl failed: %s\n", curl_easy_strerror(retcode));
}

void NTNXCreateVirtualMachine(Connection con, char* data) {
  CURLcode retcode;
  Operation op;

  retcode = httpRequest(con, RESOURCE_VM, data, op=POST);

  if(retcode != CURLE_OK)
      fprintf(stderr, "curl failed: %s\n", curl_easy_strerror(retcode));
}

void NTNXGetVirtualMachines(Connection con) {
  CURLcode retcode;
  Operation op;

  retcode = httpRequest(con, RESOURCE_VM, NULL, op=GET);

  if(retcode != CURLE_OK)
      fprintf(stderr, "curl failed: %s\n", curl_easy_strerror(retcode));
}

void NTNXGetStorageContainers(Connection con) {
  CURLcode retcode;
  Operation op;

  retcode = httpRequest(con, RESOURCE_SC, NULL, op=GET);

  if(retcode != CURLE_OK)
      fprintf(stderr, "curl failed: %s\n", curl_easy_strerror(retcode));
}

void NTNXGetImages(Connection con) {
  CURLcode retcode;
  Operation op;

  retcode = httpRequest(con, RESOURCE_IM, NULL, op=GET);

  if(retcode != CURLE_OK)
      fprintf(stderr, "curl failed: %s\n", curl_easy_strerror(retcode));
}
