/* To be improved.
* Expected syntax to generate the correct yaml file from command line:
* ./generator 'inputFile' 'outputFile'
* COMPILE WITH: c++ -o yaml_datafiles_generator.cpp yaml_datafiles_generator.exe
*********************************************************************************/

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string.h>

using namespace std;

int main(int argc, char* argv[])
{
    
    string ind_var, dep_var, err;
    string ind_var_unit, dep_var_unit, err_unit;
    string line;
    
    ifstream dummy(argv[1]);
    
    int n=0;
    
    while(!dummy.eof()){
        getline(dummy, line);
        n=n+1;
    }
    n=n-3;
    
    dummy.close();
    
	ifstream data(argv[1]);
	ofstream yaml(argv[2]);
    
    data >> ind_var >> dep_var >> err;
    data >> ind_var_unit >> dep_var_unit >> err_unit;
    
    double x[n], y[n], e[n];
    
    int i=0;
    
    while(!data.eof()){
		data >> x[i] >> y[i] >> e[i];
        i=i+1;
	}
	
	yaml << "name: '" << argv[2] << "'" << "\n";
	yaml << "independent_variables:" << "\n";
	yaml << " - header: {name: " << ind_var << ", units: " << ind_var_unit << "}" << "\n";
	yaml << "   values:" << "\n";

	for(i=0; i<n; i++){
        yaml << "    - value : " << x[i] << "\n";
    }
        
    yaml << "dependent_variables:" << "\n";
    yaml << " - header: {name: " << dep_var << ", units: " << dep_var_unit << "}" << "\n";
    yaml << "   qualifiers:" << "\n";
	yaml << "    - {name: '', value: ''}" << "\n";
    yaml << "   values:" << "\n";
        
    for(i=0; i<n; i++){
        yaml << "     - value: " << y[i] << "\n";
		yaml << "       errors:" << "\n";
		yaml << "         - {symerror: " << e[i] << ", label: stat}" << "\n";
    }

    data.close();
	yaml.close();
    
	return 0;
}
