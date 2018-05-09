class PV
{public:
  PV(const string, unsigned int);
  PV* ret_left();
  PV* ret_right();
  void set_left(PV*);
  void set_right(PV*);
  string ret_value();
  void reset_counter();
  void flip counter();
  void add_reference(PV*, unsigned int);
  vector<PV*> return_references(unsigned int);
private:
	PV* left;
	PV* right;
	string value;
	unsigned int counter;
	vector< vector<PV*> > column_values; /*for storing references to the columns'
	possible values, this will have a vector for each column.*/
};

PV::PV(const string v, unsigned int number_of_columns)
{value = v;
left = NULL;
right = NULL;
counter = 0;
column_values = vector<PV*>(number_of_columns);//??possily receive the collector sring here?
}

PV* PV::ret_left()
{return left;}

PV* PV::ret_right()
{return right;}

void PV::set_left(PV* l)
{left = l;}

void PV::set_right(PV* r)
{right = r;}

string PV::ret_value()
{return value;}

void PV::reset_counter()
{counter = 0;}

void PV::flip counter()
{counter++;}

void PV::add_reference(PV* pv, unsigned int i)
{column_values[i].push_back(pv);
}

vector<PV*> PV::return_references(unsigned int column_index)
{return column_values[column_index];
}
