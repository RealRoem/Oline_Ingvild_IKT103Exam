#ifndef IMPORTEXPORTCONTROLLER_H
#define IMPORTEXPORTCONTROLLER_H

#include "storage.h"
#include <string>

using namespace std;

class ImportExportController {
public:
    static void exportData(Storage &storage, const string &filename);
    static void importData(Storage &storage, const string &filename);

private:
    // Helper functions for JSON formatting
    static string escapeJson(const string &str);
    static string unescapeJson(const string &str);
};

#endif //IMPORTEXPORTCONTROLLER_H