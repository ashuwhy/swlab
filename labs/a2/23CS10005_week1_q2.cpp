// author: Ashutosh Sharma

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <cfloat>

using namespace std;

struct Employee {
    string name;
    string organization;
    string passcode;
    vector<pair<string, double>> monthlySalaries; // {month, salary}
    double averageSalary;
};

bool compareMonths(const pair<string, double>& a, const pair<string, double>& b) {
    map<string, int> monthOrder = {
        {"Jan", 1}, {"Feb", 2}, {"Mar", 3}, {"Apr", 4}, {"May", 5}, {"Jun", 6},
        {"Jul", 7}, {"Aug", 8}, {"Sep", 9}, {"Oct", 10}, {"Nov", 11}, {"Dec", 12}
    };
    return monthOrder[a.first] < monthOrder[b.first];
}

double roundToNearest(double value) {
    return round(value);
}

void processUserData(vector<Employee>& employees, map<string, int>& orgFrequency, map<string, vector<double>>& orgSalaries, map<string, int>& monthFrequency, int& totalPassLength, int& passCount) {
    ifstream inputFile("users.txt");
    string line;

    while (getline(inputFile, line)) {
        stringstream ss(line);
        string name, organization, passcode, salaryEntry;

        getline(ss, name, ',');
        name = name.substr(5); // removing the 'user_' prefix

        getline(ss, organization, ',');
        getline(ss, passcode, ',');

        vector<pair<string, double>> monthlySalaries;

        while (getline(ss, salaryEntry, ',')) {
            try {
                string month = salaryEntry.substr(0, 3);
                if (salaryEntry.length() <= 4) {
                    cerr << "Invalid salary format for " << name << ": " << salaryEntry << endl;
                    continue;
                }
                string salaryStr = salaryEntry.substr(4);
                salaryStr.erase(remove(salaryStr.begin(), salaryStr.end(), '\''), salaryStr.end());
                
                double salaryValue = stod(salaryStr);
                monthlySalaries.push_back({month, salaryValue});
            } catch (const std::exception& e) {
                cerr << "Error parsing salary for " << name << ": " << salaryEntry << endl;
                cerr << "Error details: " << e.what() << endl;
                continue;
            }
        }

        sort(monthlySalaries.begin(), monthlySalaries.end(), compareMonths);

        double totalSalary = 0;
        int salaryCount = 0;
        for (auto& data : monthlySalaries) {
            totalSalary += roundToNearest(data.second);
            salaryCount++;
        }
        double averageSalary = salaryCount > 0 ? totalSalary / salaryCount : 0;

        if (passcode.length() < 9) {
            passcode += "__WEAK_PASSWORD";
        }

        employees.push_back({name, organization, passcode, monthlySalaries, averageSalary});

        totalPassLength += passcode.length();
        passCount++;

        orgFrequency[organization]++;
        orgSalaries[organization].push_back(averageSalary);
        for (auto& data : monthlySalaries) {
            monthFrequency[data.first]++;
        }
    }

    inputFile.close();
}

void writeCleanedData(const vector<Employee>& employees) {
    ofstream outputFile("new_users.txt");

    for (const auto& employee : employees) {
        outputFile << employee.name << "," << employee.organization << ","
                   << employee.passcode;

        for (const auto& data : employee.monthlySalaries) {
            outputFile << "," << data.first << "-" << roundToNearest(data.second);
        }

        outputFile << ",Mean_Salary-" << roundToNearest(employee.averageSalary) << endl;
    }

    outputFile.close();
}

void analyzeData(const vector<Employee>& employees, const map<string, int>& orgFrequency, const map<string, vector<double>>& orgSalaries, const map<string, int>& monthFrequency, int totalPassLength, int passCount) {
    int weakPasswordCount = 0;
    for (const auto& employee : employees) {
        if (employee.passcode.find("__WEAK_PASSWORD") != string::npos) {
            weakPasswordCount++;
        }
    }
    cout << "Total number of weak passwords: " << weakPasswordCount << endl << endl;

    int avgPasswordLength = totalPassLength / passCount;
    cout << "Average password length: " << avgPasswordLength << endl << endl;

    string longestName = "", shortestName = "";
    for (const auto& employee : employees) {
        if (employee.name.length() > longestName.length()) {
            longestName = employee.name;
        }
        if (shortestName.empty() || employee.name.length() < shortestName.length()) {
            shortestName = employee.name;
        }
    }
    cout << "Longest username: " << longestName << endl;
    cout << "Shortest username: " << shortestName << endl << endl;

    vector<pair<string, int>> orgFreqVec(orgFrequency.begin(), orgFrequency.end());
    sort(orgFreqVec.begin(), orgFreqVec.end(), [](const pair<string, int>& a, const pair<string, int>& b) {
        return a.second > b.second;
    });
    cout << "Top-5 companies:" << endl;
    for (int i = 0; i < 5 && i < orgFreqVec.size(); ++i) {
        cout << orgFreqVec[i].first << ": " << orgFreqVec[i].second << endl;
    }
    cout << endl;

    double minSalary = DBL_MAX, maxSalary = DBL_MIN;
    for (const auto& employee : employees) {
        for (const auto& data : employee.monthlySalaries) {
            double roundedSalary = roundToNearest(data.second);
            if (roundedSalary < minSalary) {
                minSalary = roundedSalary;
            }
            if (roundedSalary > maxSalary) {
                maxSalary = roundedSalary;
            }
        }
    }
    cout << "Minimum salary: " << minSalary << endl;
    cout << "Maximum salary: " << maxSalary << endl << endl;

    string highestAvgSalaryOrg = "", lowestAvgSalaryOrg = "";
    double highestAvgSalary = DBL_MIN, lowestAvgSalary = DBL_MAX;
    for (auto& org : orgSalaries) {
        double sum = 0;
        for (double salary : org.second) {
            sum += salary;
        }
        double avgSalary = sum / org.second.size();
        if (avgSalary > highestAvgSalary) {
            highestAvgSalary = avgSalary;
            highestAvgSalaryOrg = org.first;
        }
        if (avgSalary < lowestAvgSalary) {
            lowestAvgSalary = avgSalary;
            lowestAvgSalaryOrg = org.first;
        }
    }
    cout << "Company with highest avg salary: " << highestAvgSalaryOrg << endl;
    cout << "Company with lowest avg salary: " << lowestAvgSalaryOrg << endl << endl;

    string mostFrequentMonth = "";
    int maxMonthFreq = 0;
    for (auto& month : monthFrequency) {
        if (month.second > maxMonthFreq) {
            maxMonthFreq = month.second;
            mostFrequentMonth = month.first;
        }
    }
    cout << "Most frequent month worked: " << mostFrequentMonth << endl << endl;
}

int main() {
    vector<Employee> employees;
    map<string, int> orgFrequency;
    map<string, vector<double>> orgSalaries;
    map<string, int> monthFrequency;
    int totalPassLength = 0;
    int passCount = 0;

    processUserData(employees, orgFrequency, orgSalaries, monthFrequency, totalPassLength, passCount);
    writeCleanedData(employees);
    analyzeData(employees, orgFrequency, orgSalaries, monthFrequency, totalPassLength, passCount);

    return 0;
}

