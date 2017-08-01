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
 * HTTP REST Client driver 
 * </DESC>
 */ 

#include "ntnxapi.h" 

char* HOST_IP ="10.68.69.102";
char* HOST_PORT ="9440";
char* SRVC_V2 ="/PrismGateway/services/rest/v2.0";

char* USR_NAME ="admin";
char* USR_PASSWD ="passw0rd";

int main(int argc, char *argv[]) {
  Host host = {.ip=HOST_IP, .port=HOST_PORT, .service=SRVC_V2};
  User user = {.name=USR_NAME, .passwd=USR_PASSWD};
 
  Connection con = openConnection(host, user);

  NTNXGetVirtualMachines(con);
  NTNXGetImages(con);
 
  closeConnection(con);
  return 0;
}
