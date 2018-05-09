#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <vector>
//#include <cctype>

//#include "get_type.h"
#include "pv.h"
#include "string_to_vector.h"
#include "get_until.h"

using namespace std;

int main(int argc, char* argv[])
{string file_name;
double d;
if(argc < 2)
{cout << "Please enter the name of the data file \n" <<
"(ideally should be a csv or tsv file) \nthat you want to complete:\n";
cin >> file_name;
}
else file_name = argv[1];

fstream file;
file.open(file_name.c_str());
if(!file.is_open())
{cerr << "Failed to open file " << file_name << "\n" <<
"Please check if the file is in the same folder as the executable,\n" <<
"then check whether the file name was typed correctly, and restart.\n";
exit(EXIT_FAILURE);
}

//1
string temp, line;
vector<string> current_values;
char c;

if(!getline(file,line))
{cerr << "/nThe file " << file_name << " was empty.\n";
exit(EXIT_FAILURE);
} //else nothing, business as normal, use that first line.

while(line >> noskipws >> c)
{if((isspace(c)) || (c == ',') || (c == '|') || (c == '\t')) //does this catch \n, \r, \t ?
  //looking for some sort of a delimiter
  {if(temp != "")
    {current_values.push_back(temp);
    temp = ""; //there was a delimiter, so no matter what it has, flush temp.
    } //else ;//leave it, temp is empty
  }
else
  {temp += c; //not a delimter, so let's chuck it on top and continue until we hit a delimiter
  }
}
/////////////////////////////////
if(temp != "") //this is to catch the last word on the line, might not be needed
    {current_values.push_back(temp);
    temp = "";
    }
///////////////////////////////////

//2
vector<PV*> columns, handler;
PV* newPV = NULL;
for(unsigned int i = 0; i < current_values.size(); i++)
{newPV = new PV(current_values[i]);
columns.push_back(newPV); //first PV*-s, each starts a tree.
}

//4 //tie up
for(unsigned int i = 0; i < columns.size(); i++)
{vector<PV*> V;
for(unsigned int j = 0; j < columns.size(); j++)
{if(j != i) V.push_back(columns[j]);
}
columns[i] -> add_references(V);
}

//3
//Get the res of the lines, but only as many fields as on the first one.
unsigned int counter;
while(getline(file,line))
{counter = 0;
//reset current_values here, before it gets the contents of the new line
for(unsigned int i = 0; i < current_values.size(); i++) current_values[i] = "";

while(line >> noskipws >> c && counter < curret_values.size())
{if((isspace(c)) || (c == ',') || (c == '|') || (c == '\t'))
  {counter++;//maybe just check counter here, only, and if hits threshold, break?
  if(temp != "")
    {current_values[counter] = temp;
    temp = "";
    }
  }
else
  {temp += c;
  }
}
//PV-s! Search and add to the relevant column's binary search tree.
for(unsigned i = 0; i < current_values.size(); i++)
{//search and add
}
}
//learning mode done, operation mode from here


/*The table columns have a fixed order. Use that! Vectors' elements can be accessed
directly, using the indexnumber of their elements, use that for picking Nodes for processing.
LEARNING MODE
1. Build as many strings as columns on the first line. Put them in a vector.
2. Create as many PV-s as above. Use the above string values.
3. Get data as string (if no data sent, skip), into the strings in the vector,
  search for those values on each column's binary searchtree,
  create and add to the trees new PV objects if value not found.
  Return a reference to that PV either way, and put to them into a vector.
4. Go through the whole PV* vector, and tie up each with the rest if not already done.
  There and back as pointers are unidirectional.
5. Repeat from 3. until EOF reached.

WORKING MODE
1. Empty the vector of strings. Get data into the vector of strings where data is available.
2. If none or all were available, no work can be done or needed, skip.
  Else note the ones for which there is no data available.
  Create and maintain an array of unsigned int-s, or two, one other for where there is data.
  Go through each, and for the columns where data is available,
  search for the given value, retun a reference to the found PV*, and use that
  with the array of int-s to get the suggested values for the empty columns.
  Increase counters for all candidates.
3. For each of the noted columns, there could be a PV* pointing to the
  PV that is the likely candidate for becoming the final value.
  When the counter is increased for a PV, that increased counter has to be compared with the
  current candidate's. If higher now, this is the new candidate.
4. After finishing running on the given row, the final candidate is the final value,
  write it out.*/

}
