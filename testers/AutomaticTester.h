//
// Created by Antek on 23.03.2023.
//

#ifndef INC_1_AUTOMATICTESTER_H
#define INC_1_AUTOMATICTESTER_H


class AutomaticTester {
public:
    AutomaticTester();

    static void testTable(long results[6], int i);
    static void testList(long results[6], int i);
    static void testHeap(long results[2], int i);
    static void testBST(long results[3], int i);
};


#endif //INC_1_AUTOMATICTESTER_H
