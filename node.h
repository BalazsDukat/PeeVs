class Node()
{public:
  Node(string);
  PV* add_PV(PV*, string); //SIMPLIFY THIS AND ADD A SEPARATE SEARCH VALUE FUNCTION!
  bool set_val(string);
  PV* ret_val();
  void reset_val;
private:
  string name; //column label. Not needed, the vector index will be the ID.
  PV* VALUE; //just mark one of the possible values as the current value.
  //Current value stored in a string in a vector.
  PV* PV_ROOT; //this is the root of the tree of possible values.
  PV* current; //this is for the add_PV only. Part of a searcher function?
}

Node::Node(string n)
{name = n;
VALUE = ""; //NOT SET
PV_ROOT = NULL;
current = PV_ROOT; //same address as PV_ROOT, but not modifying the original.
}

PV* Node::add_PV(PV* &current, string value)
/*this receives a string that is the value, look for it, then add a new PV if needed,
then return a pointer/reference to the new or found PV.*/
{if(current == NULL)
  {current = new PV(value);
  PV_ROOT = current; //
  return current;
  }
else
if(value < current -> ret_name())
    {current = current -> ret_left();
    return add_PV(pv);
    }
else
if(value > current -> ret_name())
    {current = current -> ret_right();
    return add_PV(pv);
    } //if it is neither smaller, nor greater, it has to be equal. Check anyway.
else
if(value == current -> ret_name())
  {return current;
  }
else cerr << "The name of the new PV is neither smaller, nor greater, nor equal.\n";
return NULL; //if all else fails, but shouldn't happen ever.
}

void Node::reset_val
{VALUE = NULL;}

