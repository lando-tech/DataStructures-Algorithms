#include "node.h"
#include <memory>

void BinaryNode::left(std::unique_ptr<BinaryNode> child)
{
    m_left = std::move(child);
    m_left->parent = this;
}

void BinaryNode::right(std::unique_ptr<BinaryNode> child)
{
    m_right = std::move(child);
    m_right->parent = this;
}

Node::Node(char character, int frequency)
{
    this->character = character;    
    this->frequency = frequency;
}

int Node::getFrequency() const
{
    return frequency;
}

char Node::getChar()
{
    return character;
}

int Comparator::operator()( const Node& leafOne, const Node& leafTwo )
{
    return leafOne.getFrequency() > leafTwo.getFrequency();
}
