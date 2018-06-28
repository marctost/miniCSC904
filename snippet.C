#include <boost/algorithm/string.hpp>

class ExcelSheet {
public:
  ExcelSheet(string filename) {
    ifstream f(filename);

  
    string line;
    while(getline(f, line)) {
      vector<string> tmpSplit;
      boost::split(tmpSplit, line, [](char c){return c == ',';});
      Row.push_back(tmpSplit);

      if(Column.size() == 0) {
	Column.resize(tmpSplit.size());
      } else if(Column.size() < tmpSplit.size()) {
	exit(1);
      }
      for(int i = 0; i < tmpSplit.size(); i++) {
	Column[i].push_back(tmpSplit.at(i));
      }
      if(Column.size() > tmpSplit.size()) {
	for(int i = tmpSplit.size(); i < Column.size(); i++) {
	  Column[i].push_back("");
	}
      }
    }
    f.close();
  }

  vector<vector<string> > Column;
  vector<vector<string> > Row;
  
};

template <typename T>
vector<T> change_type(vector<string> oldVec, T dummy) {
  vector<T> newVec;
  for(auto token : oldVec) {
    stringstream convert(token);
    T tmp;
    convert >> tmp;
    newVec.push_back(tmp);
  }
  return newVec;
}

template <typename T>
vector<T> change_type_nofirst(vector<string> oldVec, T dummy) {
  vector<T> newVec;
  for(auto iter = ++oldVec.begin(); iter != oldVec.end(); iter++) {
    stringstream convert(*iter);
    T tmp;
    convert >> tmp;
    newVec.push_back(tmp);
  }
  return newVec;
}

class PlotterLines {
public:
  PlotterLines(ExcelSheet sheet, int startRow, int endRow, int startCol) : size(endRow + 1 - startRow) {
    double dummy;
    for(int i = 0; i < 4; i++) {
      lines[i] = change_type(vector<string>(sheet.Column[startCol+i].begin()+startRow, sheet.Column[startCol+i].begin()+endRow+1), dummy);
    }
    voltages = change_type(vector<string>(sheet.Column[0].begin()+startRow, sheet.Column[0].begin()+endRow+1), dummy);
  }

  int size;
  vector<double> lines[4];
  vector<double> voltages;
};


