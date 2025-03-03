#include <bitset>
#include <climits>
#include <iostream>
#include <unordered_map>
#include <queue>
#include <vector>
#include "node.h"

// Build frequency table from input string and store in unordered_map
std::unordered_map<char, int> buildFreqTable(std::string inputString)
{
    std::unordered_map<char, int> freqTable{};     

    for (int i = 0; i < inputString.length(); i++ )
    {
        char currentChar{inputString[i]};
        if ( freqTable.find(currentChar) != freqTable.end() )
        {
            freqTable.at(currentChar)++; 
        }
        else
        {
            freqTable[currentChar] = 1;
        }
    }

    return freqTable;
}

void printFreqTable(std::unordered_map<char, int> freqTable)
{
    for ( auto& pairs : freqTable )
    {
        std::cout << pairs.first << " | " << pairs.second << '\n';
    }
}

/* Build Priority Queue based on Comparator class to ensure min-heap queue
 * Use LeafNode class to store frequency and character from the Frequency table
 */
std::priority_queue<LeafNode, std::vector<LeafNode>, Comparator> createPQueue(std::unordered_map<char, int> freqTable)
{
    std::priority_queue<LeafNode, std::vector<LeafNode>, Comparator> pq{};

    for ( auto& pairs : freqTable )
    {
        LeafNode newNode(pairs.first, pairs.second);
        pq.push(newNode);
    }
    
    return pq;
}

void printPriorityQueue(const std::priority_queue<LeafNode, std::vector<LeafNode>, Comparator>& priorityQ)
{
    auto tempPQ{priorityQ};

    while ( !tempPQ.empty() )
    {
        auto currentNode{tempPQ.top()};
        std::cout 
            << "Node Character: " << currentNode.getChar() << " | " 
            << "Node Frequency: "<< currentNode.getFrequency() 
            << '\n';
        tempPQ.pop();
    }   
}

// Return the bitset of each character in the input string
std::bitset<CHAR_BIT> getCharBitx(char c)
{
    return std::bitset<CHAR_BIT>(c);
}

int main()
{
    std::string inputString{"This is a string to compress."};
    std::unordered_map<char, int> freqTable{buildFreqTable(inputString)};
    std::priority_queue<LeafNode, std::vector<LeafNode>, Comparator> priorityQ{ 
        createPQueue(freqTable)
    };
    printPriorityQueue(priorityQ);
    
    return 0;
}

