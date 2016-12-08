/* To be improved.
* Expected syntax to generate the correct yaml file from command line:
* ./generator 'inputFile' 'outputFile'
* COMPILE WITH: c++ -o yaml_submissionfile_generator.cpp yaml_submissionfile_generator.exe
*********************************************************************************/

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string.h>

using namespace std;

int main(int argc, char* argv[])
{
    ifstream table_files(argv[1]);
    ofstream submission("submission.yaml");
    
    submission << "comment: | #Information that applies to all data tables." << "\n";
    submission << "\n\n\n\n\n";
    
    int i=1;
    string filename;
    
    while(1){
        table_files >> filename;
        
        if(table_files.eof()) break;
        
        submission << "---\n\n";
        submission << "#This is Table " << i << "\n";
        submission << "name: 'Table " << i << "'" << "\n";
        submission << "location: location to be inserted" << "\n";
        submission << "description: description to be inserted" << "\n";
        submission << "keywords: " << "\n";
        submission << " - { name: reactions, values: []}" << "\n";
        submission << " - { name: observables, values: []}" << "\n";
        submission << " - { name: cmenergies, values: []}" << "\n";
        submission << "data_file: " << filename << "\n\n\n";
        
        i=i+1;
    }

    return 0;
}
