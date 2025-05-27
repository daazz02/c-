#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
    string values;
    getline(cin, values);

    string templ;
    getline(cin, templ);

    map<string, string> dictionary;
    size_t pos = 0;
    while (pos < values.length()) {
        size_t eq_pos = values.find('=', pos);
        if (eq_pos == string::npos) break;
        string key = values.substr(pos, eq_pos - pos);

        size_t comma_pos = values.find(',', eq_pos + 1);
        string value = (comma_pos == string::npos) ? values.substr(eq_pos + 1) : values.substr(eq_pos + 1, comma_pos - eq_pos - 1);

        dictionary[key] = value;
        pos = (comma_pos == string::npos) ? values.length() : comma_pos + 1;
    }

    string output;
    for (size_t i = 0; i < templ.length(); ++i) {
        if (templ[i] == '[') {
            size_t end = templ.find(']', i);
            if (end != string::npos) {
                string key = templ.substr(i + 1, end - i - 1);
                output += dictionary.count(key) ? dictionary[key] : "[" + key + "]";
                i = end;
            } else {
                output += templ[i];
            }
        } else {
            output += templ[i];
        }
    }

    cout << output << endl;
    return 0;
}
