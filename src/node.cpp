#include "node.h"

LeafNode::LeafNode(char character, int frequency)
{
    this->frequency = frequency;
    this->character = character;
}

int LeafNode::getFrequency() const
{
    return frequency;
}

char LeafNode::getChar()
{
    return character;
}

InternalNode::InternalNode(int frequency)
{
    InternalNode node = this;
}

int Comparator::operator()( const LeafNode& leafOne, const LeafNode& leafTwo )
{
    return leafOne.getFrequency() > leafTwo.getFrequency();
}
