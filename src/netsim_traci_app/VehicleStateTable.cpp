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
    // For testing
    testFillVSTable();
    }

VehicleStateTable::~VehicleStateTable()
    {
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

std::string VehicleStateTable::getReceiverVehicleIdAt(int index)
    {
    if(index > (m_VSTable.size()-1))
        {
        // Empty string
        return "";
        }

    VSTable::iterator iter = m_VSTable.begin();
    for(int i = 0; i < index; i++)
        {
        iter++;
        }
    return iter->first;
    }

std::vector<VehicleStateTable::VehicleState> VehicleStateTable::getSenderVehicleListAt(int index)
    {
    if(index > (m_VSTable.size()-1))
        {
        // Empty vector
        return std::vector<VehicleStateTable::VehicleState>();
        }

    VSTable::iterator iter = m_VSTable.begin();
    for(int i = 0; i < index; i++)
        {
        iter++;
        }
    return iter->second;
    }

int VehicleStateTable::getTableListCount()
    {
    int rowCnt = 0;
    for(VSTable::iterator iter = m_VSTable.begin();iter != m_VSTable.end();iter++)
        {
        rowCnt++;
        }
    return rowCnt;
    }

int VehicleStateTable::getTableListItemCount()
    {
    int itemCnt = 0;
    for(VSTable::iterator iter = m_VSTable.begin();iter != m_VSTable.end();iter++)
        {
        for(unsigned int i = 0; i < iter->second.size(); i++)
            {
            itemCnt++;
            }
        }
    return itemCnt;
    }

void VehicleStateTable::displayVehicleStateTable()
    {
    bool empty = true;
    int listCnt = getTableListCount();
    int listItemCnt = getTableListItemCount();

    std::cout << "List cnt: " << listCnt << " List Item cnt: " << listItemCnt << std::endl;
    for(int i = 0; i < listCnt; i++)
        {
        empty = false;
        std::cout << "Receiver ID: " << getReceiverVehicleIdAt(i)
                    << ", Sender List: ";
        displayVehicleList(getSenderVehicleListAt(i));
        std::cout << std::endl;
        }
    if(empty)
        {
        std::cout << "Table is empty" << std::endl;
        }
    }

void VehicleStateTable::displayVehicleList(std::vector<VehicleStateTable::VehicleState> vList)
    {
    for(unsigned int i = 0; i < vList.size(); i++)
        {
        std::cout << vList.at(i).Id << "," << vList.at(i).speed << " ";
        }
    }

void VehicleStateTable::testFillVSTable()
    {
    addValueVehicleState("veh1", {"veh0", 1.0});
    addValueVehicleState("veh1", {"veh2", 1.2});

    addValueVehicleState("veh0", {"veh1", 0.1});
    addValueVehicleState("veh0", {"veh2", 0.2});

    addValueVehicleState("veh3", {"veh1", 3.1});
    addValueVehicleState("veh3", {"veh2", 3.2});
    addValueVehicleState("veh3", {"veh4", 3.4});

    addValueVehicleState("veh2", {"veh3", 2.3});

    addValueVehicleState("veh4", {"veh1", 4.1});
    addValueVehicleState("veh4", {"veh2", 4.2});
    addValueVehicleState("veh4", {"veh3", 4.3});
    }
