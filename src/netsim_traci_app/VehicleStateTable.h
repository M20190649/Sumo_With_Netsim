/*
 * VehicleStateTable.h
 *
 *  Created on: Mar 20, 2013
 *      Author: rudhir
 */

#ifndef VEHICLESTATETABLE_H_
#define VEHICLESTATETABLE_H_

#include <vector>
#include <string>
#include <map>

class VehicleStateTable
    {
    public:
    VehicleStateTable();
    virtual ~VehicleStateTable();

    void initVehicleStateTable();
    void clearVehicleStateTable();
    typedef struct
         {
         std::string Id;
         double speed;
         }VehicleState;
    void addValueVehicleState(std::string Id, VehicleState vState);
    void displayVehicleStateTable();
    void testFill();

    private:
    typedef std::map<std::string, std::vector<VehicleState> > VSTable;
    VSTable m_VSTable;
    };

#endif /* VEHICLESTATETABLE_H_ */
