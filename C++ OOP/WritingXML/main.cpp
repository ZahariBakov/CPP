#include <iostream>
#include <fstream>
#include "json.h"
#include "Library.h"

using namespace std;
using json = nlohmann::json;

void parseJson() {
    std::ifstream file("library.json");

    json Doc = json::parse(file);

    auto books = Doc["Books"];
    for (const auto & book : books) {
//        cout << book << endl;
        string title = book["title"];
        int year = book["year"];
        string genre = book["genre"];
//        cout << title << endl;
//        cout << year << endl;
//        cout << genre << endl;
        auto author = book["Author"];
//        cout << author << endl;
        string firstName = author["firstName"];
        string lastName = author["lastName"];
        string nationality = author["nationality"];
//        cout << firstName << endl;
//        cout << lastName << endl;
//        cout << nationality << endl;
    }
}

int main() {
//    parseJson();

    cout << "\nDeserializing library data (load_file_input.xml).....Started\n\n";
    Library::getDocumentFromXML("load_file_input.xml");
    Library::deserializeLibraryData();
    for (const auto b: Library::getBooksList()) {
        cout << *b << endl;
    }
    cout << "\nDeserializing library data (load_file_input.xml).....Done\n\n";

    cout << "\nSerializing library data (save_file_output.xml)...... Started\n";
    Library::generateLibraryData();
    Library::serializeLibraryData();
    Library::saveDocumentToXML("save_file_output.xml");
    cout << "\nSerializing library data (save_file_output.xml)...... Done\n\n";
    return 0;
}
