#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Activity
{
protected:
    int date;
    int msbn;

public:
    Activity(int d, int m) : date(d), msbn(m) {}
    virtual void Process() = 0;
};

class Patient
{
protected:
    int msbn;
    string name;
    string type;
    int admissionDate;
    int dischargeDate;
    int outpatientFee;
    int inpatientFee;
    string roomType;

public:
    Patient(int m, string n, string t, int ad, int dd, int of, int ifee, string rt)
        : msbn(m), name(n), type(t), admissionDate(ad), dischargeDate(dd),
          outpatientFee(of), inpatientFee(ifee), roomType(rt) {}
    virtual int CalculateFee() = 0;
};

class Hospital
{
private:
    vector<Patient *> patients;
    int revenue;

public:
    Hospital() : revenue(0) {}
    void AddPatient(Patient *p)
    {
        patients.push_back(p);
    }
    void PrintSummary()
    {
        cout << "Total revenue: " << revenue << " VND" << endl;
        cout << "Total inpatients: " << CountInpatients() << endl;
        cout << "Total outpatients: " << CountOutpatients() << endl;
    }
    int CountInpatients()
    {
        int count = 0;
        for (Patient *p : patients)
        {
            if (p->CalculateFee() > 0)
            {
                count++;
            }
        }
        return count;
    }
    int CountOutpatients()
    {
        int count = 0;
        for (Patient *p : patients)
        {
            if (p->CalculateFee() == 0)
            {
                count++;
            }
        }
        return count;
    }
};

class OutpatientPatient : public Patient
{
public:
    OutpatientPatient(int m, string n, string t, int ad, int dd, int of, int ifee, string rt)
        : Patient(m, n, t, ad, dd, of, ifee, rt) {}

    int CalculateFee() override
    {
        // Implement the calculation for outpatient fee
        return outpatientFee;
    }

    void Process()
    {
        // Implement the processing for outpatient activity
        cout << "Processing outpatient activity for patient " << msbn << endl;
    }
};

class InpatientPatient : public Patient
{
public:
    InpatientPatient(int m, string n, string t, int ad, int dd, int of, int ifee, string rt)
        : Patient(m, n, t, ad, dd, of, ifee, rt) {}

    int CalculateFee() override
    {
        // Implement the calculation for inpatient fee
        return dischargeDate * (inpatientFee + (roomType == "A" ? 1400000 : (roomType == "B" ? 900000 : 600000)));
    }

    void Process()
    {
        // Implement the processing for inpatient activity
        cout << "Processing inpatient activity for patient " << msbn << endl;
    }
};

int main()
{
    // Sample usage
    Hospital hospital;
    OutpatientPatient outpatient(1, "John Doe", "Outpatient", 1, 0, 20000, 0, "");
    InpatientPatient inpatient(2, "Jane Doe", "Inpatient", 2, 0, 0, 100000, "B");

    hospital.AddPatient(&outpatient);
    hospital.AddPatient(&inpatient);

    outpatient.Process();
    inpatient.Process();

    hospital.PrintSummary();

    return 0;
}