#include <iostream>
#include <vector>
#include <string>

// Base class representing a general contract
class Contract
{
public:
    std::string customerName;
    std::string idNumber;
    std::string address;

    virtual void calculateTotalCharge() = 0;
    virtual void displayContractDetails() = 0;
};

// Derived class for Basic Contract
class BasicContract : public Contract
{
public:
    int callDuration;    // in minutes
    int internetUsage;   // in MB
    double callRate;     // per minute
    double internetRate; // per MB

    void calculateTotalCharge() override
    {
        double callCharge = callDuration * callRate;
        double internetCharge = internetUsage * internetRate;
        double totalCharge = callCharge + internetCharge + (callCharge + internetCharge) * 0.1;
        std::cout << "Total Charge: " << totalCharge << " VND" << std::endl;
    }

    void displayContractDetails() override
    {
        std::cout << "Basic Contract Details:" << std::endl;
        // Display details specific to Basic Contract
    }
};

// Derived class for Data Free Contract
class DataFreeContract : public BasicContract
{
public:
    int freeInternetThreshold;

    void calculateTotalCharge() override
    {
        if (internetUsage <= freeInternetThreshold)
        {
            double totalCharge = (callDuration * callRate) + ((callDuration * callRate) * 0.1);
            std::cout << "Total Charge: " << totalCharge << " VND" << std::endl;
        }
        else
        {
            double callCharge = callDuration * callRate;
            double internetCharge = internetUsage * internetRate;
            double totalCharge = callCharge + internetCharge + (callCharge + internetCharge) * 0.1;
            std::cout << "Total Charge: " << totalCharge << " VND" << std::endl;
        }
    }

    void displayContractDetails() override
    {
        std::cout << "Data Free Contract Details:" << std::endl;
        // Display details specific to Data Free Contract
    }
};

// Derived class for Data Fix Contract
class DataFixContract : public BasicContract
{
public:
    double discountPercentage;
    double fixedCharge;

    void calculateTotalCharge() override
    {
        double callCharge = callDuration * callRate;
        double internetCharge = internetUsage * internetRate;
        double totalCharge = (callCharge + internetCharge - (callCharge + internetCharge) * discountPercentage) + fixedCharge;
        std::cout << "Total Charge: " << totalCharge << " VND" << std::endl;
    }

    void displayContractDetails() override
    {
        std::cout << "Data Fix Contract Details:" << std::endl;
        // Display details specific to Data Fix Contract
    }
};

// Class representing the company managing contracts
class TelecomCompany
{
public:
    std::vector<Contract *> contracts;

    void addContract(Contract *contract)
    {
        contracts.push_back(contract);
    }

    void notifyAllContracts()
    {
        for (const auto &contract : contracts)
        {
            contract->calculateTotalCharge();
            contract->displayContractDetails();
            std::cout << "---------------------" << std::endl;
        }
    }
};

int main()
{
    TelecomCompany company;

    // Example contracts
    BasicContract basicContract;
    basicContract.customerName = "John Doe";
    basicContract.callDuration = 100;
    basicContract.internetUsage = 500;
    basicContract.callRate = 1000.0;
    basicContract.internetRate = 200.0;

    DataFreeContract dataFreeContract;
    dataFreeContract.customerName = "Jane Doe";
    dataFreeContract.callDuration = 120;
    dataFreeContract.internetUsage = 300;
    dataFreeContract.callRate = 1000.0;
    dataFreeContract.internetRate = 200.0;
    dataFreeContract.freeInternetThreshold = 500;

    DataFixContract dataFixContract;
    dataFixContract.customerName = "Bob Smith";
    dataFixContract.callDuration = 150;
    dataFixContract.internetUsage = 600;
    dataFixContract.callRate = 1000.0;
    dataFixContract.internetRate = 200.0;
    dataFixContract.discountPercentage = 0.1;
    dataFixContract.fixedCharge = 1000000.0;

    // Add contracts to the company
    company.addContract(&basicContract);
    company.addContract(&dataFreeContract);
    company.addContract(&dataFixContract);

    // Notify all contracts at the end of the month
    company.notifyAllContracts();

    return 0;
}