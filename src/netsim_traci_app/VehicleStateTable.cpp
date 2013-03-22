/*
 * NbTable.cpp
 *
 *  Created on: Mar 20, 2013
 *      Author: rudhir
 */
#include <algorithm>
#include <iostream>
#include "VehicleStateTable.h"

VehicleStateTable::VehicleStateTable()
    {
    // TODO Auto-generated constructor stub
    }

VehicleStateTable::~VehicleStateTable()
    {
    // TODO Auto-generated destructor stub
    }

void VehicleStateTable::initVehicleStateTable()
    {
    }

void VehicleStateTable::clearVehicleStateTable()
    {
    // Erase all the keys
    m_VSTable.erase(m_VSTable.begin(), m_VSTable.end());
    }

void VehicleStateTable::addValueVehicleState(std::string Id, VehicleState vState)
    {
    VSTable::iterator iter = m_VSTable.find(Id);
    if (iter != m_VSTable.end())
        {
        // Key exists. Add value to the end of the vector.
        iter->second.push_back(vState);
        }
    else
        {
        // Key does not exist. Add new key and new value to the vector.
        m_VSTable[Id].push_back(vState);
        }
    }

void VehicleStateTable::displayVehicleStateTable()
    {
    bool empty = true;

    for(VSTable::iterator iter = m_VSTable.begin();iter != m_VSTable.end();iter++)
        {
        empty = false;
        std::cout << "Recv Id " << iter->first << ": ";
        for(unsigned int i = 0; i < iter->second.size(); i++)
            {
            std::cout << "(" << iter->second.at(i).Id << ", "
                    << iter->second.at(i).speed << ")" << " ";
            }
        std::cout << std::endl;
        }

    if(empty)
        {
        std::cout << "Table is empty" << std::endl;
        }
    }

void VehicleStateTable::testFill()
    {
#if 0
    addValueVehicleState("veh1", {"veh0", 1.0});
    addValueVehicleState("veh1", {"veh2", 1.2});

    addValueVehicleState("veh0", {"veh1", 0.1});
    addValueVehicleState("veh0", {"veh2", 0.2});

    addValueVehicleState("veh3", {"veh1", 3.1});
    addValueVehicleState("veh3", {"veh2", 3.2});
    addValueVehicleState("veh3", {"veh4", 3.4});

    addValueVehicleState("veh2", {"veh1", 2.1});
    addValueVehicleState("veh2", {"veh3", 2.3});

    addValueVehicleState("veh4", {"veh1", 4.1});
    addValueVehicleState("veh4", {"veh2", 4.2});
    addValueVehicleState("veh4", {"veh3", 4.3});
#endif
    }
