#include "ImportExportController.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <algorithm>
#include "Car.h"
#include "Customer.h"
#include "Rental.h"

using namespace std;

void ImportExportController::exportData(Storage &storage, const string &filename) {
    ofstream file(filename);
    if (!file.is_open()) {
        cout << "Error: Could not open file for export: " << filename << endl;
        return;
    }

    file << "{\n";

    // Export cars
    file << "  \"cars\": [\n";
    auto cars = storage.get_all<Car>();
    for (size_t i = 0; i < cars.size(); ++i) {
        const auto& car = cars[i];
        file << "    {\n";
        file << "      \"regNo\": \"" << escapeJson(car.regNo) << "\",\n";
        file << "      \"carModel\": \"" << escapeJson(car.carModel) << "\",\n";
        file << "      \"seats\": " << car.seats << ",\n";
        file << "      \"gearbox\": \"" << escapeJson(car.gearbox) << "\",\n";
        file << "      \"dailyRentalCost\": " << car.dailyRentalCost << "\n";
        file << "    }";
        if (i < cars.size() - 1) file << ",";
        file << "\n";
    }
    file << "  ],\n";

    // Export customers
    file << "  \"customers\": [\n";
    auto customers = storage.get_all<Customer>();
    for (size_t i = 0; i < customers.size(); ++i) {
        const auto& customer = customers[i];
        file << "    {\n";
        file << "      \"customerId\": " << customer.customerId << ",\n";
        file << "      \"customerName\": \"" << escapeJson(customer.customerName) << "\",\n";
        file << "      \"dateofBirth\": \"" << escapeJson(customer.dateofBirth) << "\",\n";
        file << "      \"mail\": \"" << escapeJson(customer.mail) << "\",\n";
        file << "      \"phonenumber\": \"" << escapeJson(customer.phonenumber) << "\"\n";
        file << "    }";
        if (i < customers.size() - 1) file << ",";
        file << "\n";
    }
    file << "  ],\n";

    // Export rentals
    file << "  \"rentals\": [\n";
    auto rentals = storage.get_all<Rental>();
    for (size_t i = 0; i < rentals.size(); ++i) {
        const auto& rental = rentals[i];
        file << "    {\n";
        file << "      \"customerId\": " << rental.customerId << ",\n";
        file << "      \"regNo\": \"" << escapeJson(rental.regNo) << "\",\n";
        file << "      \"startTime\": \"" << escapeJson(rental.startTime) << "\",\n";
        file << "      \"status\": " << (rental.status ? "true" : "false") << "\n";
        file << "    }";
        if (i < rentals.size() - 1) file << ",";
        file << "\n";
    }
    file << "  ]\n";

    file << "}\n";
    file.close();

    cout << "Data exported successfully to: " << filename << endl;
}

void ImportExportController::importData(Storage &storage, const string &filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Error: Could not open file for import: " << filename << endl;
        return;
    }

    stringstream buffer;
    buffer << file.rdbuf();
    string content = buffer.str();
    file.close();

    // Import cars
    size_t carsStart = content.find("\"cars\": [");
    if (carsStart != string::npos) {
        size_t carsEnd = content.find("]", carsStart);
        size_t carPos = content.find("{", carsStart);

        while (carPos < carsEnd && carPos != string::npos) {
            size_t carEndPos = content.find("}", carPos);
            if (carEndPos == string::npos) break;

            string carJson = content.substr(carPos, carEndPos - carPos + 1);

            Car car;

            // Extract regNo
            size_t regNoPos = carJson.find("\"regNo\": \"");
            if (regNoPos != string::npos) {
                regNoPos += 10;
                size_t regNoEnd = carJson.find("\"", regNoPos);
                car.regNo = unescapeJson(carJson.substr(regNoPos, regNoEnd - regNoPos));
            }

            // Extract carModel
            size_t modelPos = carJson.find("\"carModel\": \"");
            if (modelPos != string::npos) {
                modelPos += 13;
                size_t modelEnd = carJson.find("\"", modelPos);
                car.carModel = unescapeJson(carJson.substr(modelPos, modelEnd - modelPos));
            }

            // Extract seats
            size_t seatsPos = carJson.find("\"seats\": ");
            if (seatsPos != string::npos) {
                seatsPos += 9;
                size_t seatsEnd = carJson.find(",", seatsPos);
                car.seats = stoi(carJson.substr(seatsPos, seatsEnd - seatsPos));
            }

            // Extract gearbox
            size_t gearboxPos = carJson.find("\"gearbox\": \"");
            if (gearboxPos != string::npos) {
                gearboxPos += 12;
                size_t gearboxEnd = carJson.find("\"", gearboxPos);
                car.gearbox = unescapeJson(carJson.substr(gearboxPos, gearboxEnd - gearboxPos));
            }

            // Extract dailyRentalCost
            size_t costPos = carJson.find("\"dailyRentalCost\": ");
            if (costPos != string::npos) {
                costPos += 18;
                size_t costEnd = carJson.find("\n", costPos);
                if (costEnd == string::npos) costEnd = carJson.find("}", costPos);
                car.dailyRentalCost = stoi(carJson.substr(costPos, costEnd - costPos));
            }

            storage.replace(car);
            carPos = content.find("{", carEndPos);
        }
    }

    // Import customers
    size_t customersStart = content.find("\"customers\": [");
    if (customersStart != string::npos) {
        size_t customersEnd = content.find("]", customersStart);
        size_t customerPos = content.find("{", customersStart);

        while (customerPos < customersEnd && customerPos != string::npos) {
            size_t customerEndPos = content.find("}", customerPos);
            if (customerEndPos == string::npos) break;

            string customerJson = content.substr(customerPos, customerEndPos - customerPos + 1);

            Customer customer;

            // Extract customerId
            size_t idPos = customerJson.find("\"customerId\": ");
            if (idPos != string::npos) {
                idPos += 14;
                size_t idEnd = customerJson.find(",", idPos);
                customer.customerId = stoi(customerJson.substr(idPos, idEnd - idPos));
            }

            // Extract customerName
            size_t namePos = customerJson.find("\"customerName\": \"");
            if (namePos != string::npos) {
                namePos += 17;
                size_t nameEnd = customerJson.find("\"", namePos);
                customer.customerName = unescapeJson(customerJson.substr(namePos, nameEnd - namePos));
            }

            // Extract dateofBirth
            size_t dobPos = customerJson.find("\"dateofBirth\": \"");
            if (dobPos != string::npos) {
                dobPos += 16;
                size_t dobEnd = customerJson.find("\"", dobPos);
                customer.dateofBirth = unescapeJson(customerJson.substr(dobPos, dobEnd - dobPos));
            }

            // Extract mail
            size_t mailPos = customerJson.find("\"mail\": \"");
            if (mailPos != string::npos) {
                mailPos += 9;
                size_t mailEnd = customerJson.find("\"", mailPos);
                customer.mail = unescapeJson(customerJson.substr(mailPos, mailEnd - mailPos));
            }

            // Extract phonenumber
            size_t phonePos = customerJson.find("\"phonenumber\": \"");
            if (phonePos != string::npos) {
                phonePos += 16;
                size_t phoneEnd = customerJson.find("\"", phonePos);
                customer.phonenumber = unescapeJson(customerJson.substr(phonePos, phoneEnd - phonePos));
            }

            // For customers, check if it exists first
            auto existing = storage.get_pointer<Customer>(customer.customerId);
            if (existing) {
                storage.update(customer);
            } else {
                storage.insert(customer);
            }

            customerPos = content.find("{", customerEndPos);
        }
    }

    // Import rentals
    size_t rentalsStart = content.find("\"rentals\": [");
    if (rentalsStart != string::npos) {
        size_t rentalsEnd = content.find("]", rentalsStart);
        size_t rentalPos = content.find("{", rentalsStart);

        while (rentalPos < rentalsEnd && rentalPos != string::npos) {
            size_t rentalEndPos = content.find("}", rentalPos);
            if (rentalEndPos == string::npos) break;

            string rentalJson = content.substr(rentalPos, rentalEndPos - rentalPos + 1);

            Rental rental;

            // Extract customerId
            size_t idPos = rentalJson.find("\"customerId\": ");
            if (idPos != string::npos) {
                idPos += 14;
                size_t idEnd = rentalJson.find(",", idPos);
                rental.customerId = stoi(rentalJson.substr(idPos, idEnd - idPos));
            }

            // Extract regNo
            size_t regNoPos = rentalJson.find("\"regNo\": \"");
            if (regNoPos != string::npos) {
                regNoPos += 10;
                size_t regNoEnd = rentalJson.find("\"", regNoPos);
                rental.regNo = unescapeJson(rentalJson.substr(regNoPos, regNoEnd - regNoPos));
            }

            // Extract startTime
            size_t timePos = rentalJson.find("\"startTime\": \"");
            if (timePos != string::npos) {
                timePos += 14;
                size_t timeEnd = rentalJson.find("\"", timePos);
                rental.startTime = unescapeJson(rentalJson.substr(timePos, timeEnd - timePos));
            }

            // Extract status
            size_t statusPos = rentalJson.find("\"status\": ");
            if (statusPos != string::npos) {
                statusPos += 10;
                string statusStr = rentalJson.substr(statusPos, 5);
                rental.status = (statusStr.find("true") != string::npos);
            }

            // For rentals with composite keys, we need to handle it differently
            try {
                storage.replace(rental);
            } catch (...) {
                // If replace fails, try insert
                try {
                    storage.insert(rental);
                } catch (...) {
                    cout << "Warning: Could not import rental (regNo: " << rental.regNo
                         << ", startTime: " << rental.startTime << ")" << endl;
                }
            }

            rentalPos = content.find("{", rentalEndPos);
        }
    }

    cout << "Data imported successfully from: " << filename << endl;
}

string ImportExportController::escapeJson(const string &str) {
    string result;
    for (char c : str) {
        switch (c) {
            case '"': result += "\\\""; break;
            case '\\': result += "\\\\"; break;
            case '\b': result += "\\b"; break;
            case '\f': result += "\\f"; break;
            case '\n': result += "\\n"; break;
            case '\r': result += "\\r"; break;
            case '\t': result += "\\t"; break;
            default: result += c;
        }
    }
    return result;
}

string ImportExportController::unescapeJson(const string &str) {
    string result;
    for (size_t i = 0; i < str.length(); ++i) {
        if (str[i] == '\\' && i + 1 < str.length()) {
            switch (str[i + 1]) {
                case '"': result += '"'; i++; break;
                case '\\': result += '\\'; i++; break;
                case 'b': result += '\b'; i++; break;
                case 'f': result += '\f'; i++; break;
                case 'n': result += '\n'; i++; break;
                case 'r': result += '\r'; i++; break;
                case 't': result += '\t'; i++; break;
                default: result += str[i];
            }
        } else {
            result += str[i];
        }
    }
    return result;
}