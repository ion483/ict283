#include "Time_1.h"
#include "Date.h"
#include "Vector.h"
#include "Calculation.h"
#include "Map.h"
#include "Collection.h"
#include "WindRecType.h"
#include "Read.h"
#include "Read2.h"
#include "Menu.h"
#include "Menu2.h"
#include "IntBST.h"
#include "BST.h"
#include <fstream>
#include <map>
#include <sstream>
#include <cstdio>
#include <algorithm>

template <class X>
void functionPointer(void (Collection<X>::* funcPtr)() const){
    Collection<X> c;
    (c.*funcPtr)();
}

int main(){
    /*std::map<int, int> m = {{1, 2}, {3, 4}};
    auto it = m.begin();
    auto cit = m.cbegin();
    bool result = (it == cit);
    std::cout << result << std::endl;
    */ /*1*/

    /*
    Time_1 t;
    Date d;
    Vector<int> v;
    Vector<int> v2;
    /*
    std::ifstream ifs("data.txt");
    if(!ifs){
        return -1;
    }
    ifs >> d;
    std::cout << d << std::endl;
    */
    /*
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    v2.push_back(4);
    v2.push_back(5);
    v2.push_back(6);

    Vector<int> v3 = v2;

    std::cout << v << '\n';
    v = v2;
    std::cout << v << std::endl;
    std::cout << v3 << std::endl;
    */

    /*
    Map<int, std::string> m;
    m[1] = "Hello";
    m[2] = "World";
    std::cout << m << std::endl;
    */

    /*
    Calculation c;
    Vector<double> v4;
    v4.push_back(4.0);
    v4.push_back(1.0);
    v4.push_back(3.0);
    v4.push_back(2.0);
    v4.push_back(5.0);
    v4.push_back(2.0);
    v4.push_back(4.0);
    v4.push_back(5.0);

    Vector<double> v5;
    v5.push_back(504.0);
    v5.push_back(501.0);
    v5.push_back(503.0);
    v5.push_back(502.0);
    v5.push_back(505.0);
    v5.push_back(502.0);
    v5.push_back(504.0);
    v5.push_back(505.0);

    Vector<double> v6;
    v6.push_back(504.0);
    v6.push_back(504.0);
    v6.push_back(505.0);
    v6.push_back(501.0);
    v6.push_back(503.0);
    v6.push_back(505.0);
    v6.push_back(502.0);
    v6.push_back(502.0);

    std::cout << v4 << std::endl;

    Vector<double> sorted = v4.getSortedData();
    std::cout << sorted << std::endl;

    std::cout << "Median: " << c.calculateMedian(v4) << std::endl;

    double stddev4 = c.calculateSampleStdDev(v4, c.calculateMean(v4));
    double mad4 = c.calculateMAD(v4, c.calculateMedian(v4));

    std::cout << "stddev4: " << stddev4 << '\n';
    std::cout << "mad4: " << mad4 << std::endl;

    double stddev5 = c.calculateSampleStdDev(v5, c.calculateMean(v5));
    double mad5 = c.calculateMAD(v5, c.calculateMedian(v5));

    std::cout << "stddev5: " << stddev5 << '\n';
    std::cout << "mad5: " << mad5 << std::endl;

    double spcc45 = c.calculatesPCC(v4, v5);
    std::cout << "spcc45: " << spcc45 << std::endl;

    double spcc46 = c.calculatesPCC(v4, v6);
    std::cout << "spcc46: " << spcc46 << std::endl;
    */

    /*
    Collection<int> collection;
    collection.collect(1);
    collection.collect(2);
    collection.collect(3);
    std::cout << collection << std::endl;
    */

    /*
    Date d(2015, 10, 10);
    std::cout << d << std::endl;
    */

    /*
    WindRecType w;
    w.d = Date(2020, 10, 10);
    w.t = Time_1(20, 10, 50);
    w.speed = 10.0;
    w.airT = 25.0;
    w.sr = 5.0;

    WindRecType w2;
    w2.d = Date(2021, 10, 10);
    w2.t = Time_1(23, 10, 50);
    w2.speed = 10.5;
    w2.airT = 25.5;
    w2.sr = 5.5;

    std::cout << w << std::endl;
    std::cout << w2 << std::endl;
    */

    /*
    Vector<WindRecType> v;
    Read r("Data_source.txt", v);
    r.readCSV();
    Calculation c;

    Menu m(v, c);
    m.run();
    */

    /*
    IntBST ibst;
    ibst.insert(2);
    ibst.insert(1);
    ibst.insert(3);
    ibst.inOrderTraversal();
    ibst.preOrderTraversal();
    ibst.postOrderTraversal();

    ibst.search(2);

    ibst.deleteNode(2);
    ibst.inOrderTraversal();
    ibst.preOrderTraversal();
    ibst.postOrderTraversal();
    
    ibst.search(2);
    */

    /*
    BST<int> b;
    b.insert(2);
    b.insert(1);
    b.insert(3);
    b.inOrderTraversal();
    b.preOrderTraversal();
    b.postOrderTraversal();
    b.search(2);
    b.deleteNode(2);
    b.inOrderTraversal();
    b.preOrderTraversal();
    b.postOrderTraversal();
    b.search(2);
    */

    /*
    std::ifstream ifs("data_source/MetData_Jan01-2010-Jan01-2011-ALL.csv");
    int index = 0;
    Vector<WindRecType> vw;
    BST<WindRecType> bst;

    std::string header;
    std::getline(ifs, header);
    std::istringstream hiss(header);
    const char delimiter = ',';
    std::string headerCell;
    Vector<std::string> headerV;
    while(std::getline(hiss, headerCell, delimiter)){
        headerV.push_back(headerCell);
    }
    int dateIdx = -1, wsIdx = -1, tempIdx = -1, srIdx = -1;
    for(int i = 0; i < headerV.size(); i++){
        if(headerV[i] == "WAST") dateIdx = i;
        else if(headerV[i] == "S") wsIdx = i;
        else if(headerV[i] == "T") tempIdx = i;
        else if(headerV[i] == "SR") srIdx = i;
    }
    std::string entryStr;
    while(std::getline(ifs, entryStr)){
        std::istringstream eiss(entryStr);
        std::string entryCell;
        Vector<std::string> entryV;
        while(std::getline(eiss, entryCell, delimiter)){
            entryV.push_back(entryCell);
        }
        std::string dateStr, wsStr, tempStr, srStr;
        dateStr = entryV[dateIdx];
        wsStr = entryV[wsIdx];
        tempStr = entryV[tempIdx];
        srStr = entryV[srIdx];

        WindRecType w;

        if(!dateStr.empty()){
            int day, month, year, hour, minute;
            int result = std::sscanf(dateStr.c_str(), "%d/%d/%d %d:%d", &day, &month, &year, &hour, &minute);
            if(result != 5){
                continue;
            }
            w.d = Date(year, month, day);
            w.t = Time_1(hour, minute, 0);
        }else{
            continue;
        }

        try{
            if(!wsStr.empty()){
                double speed = std::stod(wsStr);
                w.speed = speed;
            }
        }catch(const std::invalid_argument& e){

        }

        try{
            if(!tempStr.empty()){
                double temp = std::stod(tempStr);
                w.airT = temp;
            }
        }catch(const std::invalid_argument& e){

        }

        try{
            if(!srStr.empty()){
                double sr = std::stod(srStr);
                w.sr = sr;
            }
        }catch(const std::invalid_argument& e){

        }
        vw.push_back(w);
        bst.insert(w);
        if(!bst.isBalanced()){
            bst.balanceItSelf();
        }
        /*
        index++;
        if(index == 5){
            break;
        }
        
    }
    
    std::cout << bst.height() << std::endl;
    */

    /*
    BST<int> intBST;
    Vector<int> intV;
    intBST.insert(1);
    intBST.insert(2);
    intBST.insert(3);
    intBST.insert(4);
    intBST.insert(5);
    intV.push_back(1);
    intV.push_back(2);
    intV.push_back(3);
    intV.push_back(4);
    intV.push_back(5);
    BST<int> intBalancedBST = intBST.buildBalancedBST(intV);
    std::cout << "original bst: \n";
    intBST.postOrderTraversal();
    std::cout << "original bst height: " << intBST.height() << '\n';
    if(intBST.isBalanced()){
        std::cout << "original bst is balanced\n";
    }else{
        std::cout << "original bst is unbalanced\n";
    }
    std::cout << "\nbalancedBST size: " << intBalancedBST.size() << '\n';
    std::cout << "balanced bst: \n";
    intBalancedBST.postOrderTraversal();
    std::cout << "balanced bst height: " << intBalancedBST.height() << '\n';
    if(intBalancedBST.isBalanced()){
        std::cout << "balanced bst is balanced\n";
    }else{
        std::cout << "balanced bst is unbalanced\n";
    }

    BST<int> intBST2;
    intBST2.insert(1);
    intBST2.insert(2);
    intBST2.insert(3);
    intBST2.insert(4);
    intBST2.insert(5);
    std::cout << "\nintbst2 before balancing itself: \n";
    intBST2.postOrderTraversal();
    if(intBST2.isBalanced()){
        std::cout << "intbst2 is balanced\n";
    }else{
        std::cout << "intbst2 is unbalanced\n";
    }

    intBST2.balanceItSelf();
    std::cout << "intbst2 after balancing itself: \n";
    intBST2.postOrderTraversal();
    if(intBST2.isBalanced()){
        std::cout << "intbst2 is balanced\n";
    }else{
        std::cout << "intbst2 is unbalanced\n";
    }
    */


    /*
    BST<int> bstint;
    bstint.insert(1);
    bstint.insert(2);
    bstint.insert(3);
    bstint.insert(4);
    bstint.insert(5);

    Collection<int> c;
    std::cout << c << '\n';
    bstint.inOrderTraversalCollect(c, &Collection<int>::collect);
    std::cout << c << '\n';
    */


    


    /*test out the bst inordertraversalcollect*/
    /*test out the real wind data with bst and balance it*/
    /*assignment2*/

    /*functionPointer(&Collection<int>::display);*/




    

    

    /*std::cout << "loaded with: " << bst.size() << " data\n";*/
    
    /*
    WindRecType w1;
    w1.d = Date(10, 10, 5);
    w1.t = Time_1(10, 40, 0);

    WindRecType w2;
    w2.d = Date(5, 10, 5);
    w2.t = Time_1(20, 40, 0);

    WindRecType w3;
    w3.d = Date(1, 10, 5);
    w3.t = Time_1(80, 40, 0);
    */

    Map<int, Map<int, BST<WindRecType>>> dataMap;
    Read2 r("Data_source.txt", dataMap);
    r.readCSV();
    Calculation c;
    Menu2 m2(dataMap, c);
    m2.run();

    /*
    const BST<WindRecType>& bst = dataMap[2010][1];
    std::cout << "size: " << bst.size() << '\n';
    std::cout << "is bst balanced: " << bst.isBalanced() << '\n';
    */

    return 0;
}
