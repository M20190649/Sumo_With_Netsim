/****************************************************************************/
/****************************************************************************/


// ===========================================================================
// included modules
// ===========================================================================
#ifdef _MSC_VER
#include <windows_config.h>
#else
#include "config.h"
#endif

#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include "NetsimTraciClient.h"
#include "MSVehicleStateTable.h"



// ===========================================================================
// used namespaces
// ===========================================================================
using namespace netsimtraciclient;


// ===========================================================================
// method definitions
// ===========================================================================
int main(int argc, char* argv[]) {
    std::string outFileName = "testclient_out.txt";
    int port = -1;
    std::string host = "localhost";
    std::string strBeginTime = "", strEndTime = "";

    if ((argc == 1) || (argc % 2 == 0)) {
        std::cout << "Usage: NetsimTraciClient -p <remote port>"
                  << "[-h <remote host>] [-o <outputfile name>]"
                  << "[-b <begin time>] [-e <end time>]"
                  << std::endl;
        return 0;
    }

    for (int i = 1; i < argc; i++) {
        std::string arg = argv[i];

        if (arg.compare("-o") == 0) {
            outFileName = argv[i + 1];
            i++;
        } else if (arg.compare("-p") == 0) {
            port = atoi(argv[i + 1]);
            i++;
        } else if (arg.compare("-h") == 0) {
            host = argv[i + 1];
            i++;
        } else if (arg.compare("-b") == 0) {
            strBeginTime = argv[i + 1];
            i++;
        } else if (arg.compare("-e") == 0) {
            strEndTime = argv[i + 1];
            i++;
        } else {
            std::cout << "unknown parameter: " << argv[i] << std::endl;
            return 1;
        }
    }

    if (port == -1) {
        std::cout << "Missing port" << std::endl;
        return 1;
    }

    ////////////////////////////////////////////
    // Start Ns3 from the given path
    ///////////////////////////////////////////

    ///////////////////////////////////////////
    // Start sumo with given remote port
    ///////////////////////////////////////////

    ///////////////////////////////////////////
    // Start TraCI Sumo Client
    ///////////////////////////////////////////
    MSVehicleStateTable* ptrVehStateTable = new MSVehicleStateTable();
    NetsimTraciClient client(ptrVehStateTable, outFileName);
    return !client.run(port, host, strBeginTime, strEndTime);

}
