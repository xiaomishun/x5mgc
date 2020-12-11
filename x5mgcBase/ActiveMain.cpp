#include "ActiveMain.h"
#include <openssl/ssl.h>


ActiveMain::ActiveMain()
{

}


ActiveMain::~ActiveMain()
{

}

void ActiveMain::run()
{
	ws.connect(SERVER_HOST, SERVER_PORT);
}
