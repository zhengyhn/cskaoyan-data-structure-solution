#include <iostream>
#include <queue>

using namespace std;

class Solution {
  public:
    string getNextTurn(string vehicles) {
      queue<char> truckQueue;
      queue<char> busQueue;
      string ret;
      for (int i = 0; i < vehicles.size(); ++i) {
        if (vehicles[i] == 'T') {
          truckQueue.push(vehicles[i]);
        } else {
          busQueue.push(vehicles[i]);
        }
      }
      int numBus = 0;
      while (ret.size() < 10) {
        if (numBus < 4) {
          if (!busQueue.empty()) {
            ret.push_back(busQueue.front());
            busQueue.pop();
          } else if (!truckQueue.empty()) {
            ret.push_back(truckQueue.front());
            truckQueue.pop();
          } else {
            return ret;
          }
          ++numBus;
        } else {
          if (!truckQueue.empty()) {
            ret.push_back(truckQueue.front());
            truckQueue.pop();
          } else if (!busQueue.empty()) {
            ret.push_back(busQueue.front());
            busQueue.pop();
          } else {
            return ret;
          }
          numBus = 0;
        }
      }
      return ret;
    }
};

int main() {
  Solution sln;
  cout << sln.getNextTurn("BBB") << endl;
  cout << sln.getNextTurn("BBBT") << endl;
  cout << sln.getNextTurn("TBBBT") << endl;
  cout << sln.getNextTurn("TBBBTBB") << endl;
  cout << sln.getNextTurn("TBBBTBBTBTBTB") << endl;
  cout << sln.getNextTurn("TBBBBBBBBB") << endl;
  cout << sln.getNextTurn("TT") << endl;

  return 0;
}