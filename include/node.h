

#include <memory>
class LeafNode
{
    public:
        LeafNode(char character, int frequency);
        char getChar();
        int getFrequency() const;
    private:
        int frequency{};
        char character{};
};

class InternalNode
{
    public:
        InternalNode(
                int frequency, 
                std::unique_ptr<LeafNode> leftNode, 
                std::unique_ptr<LeafNode> rightNode
                );
        int getFrequency();
    private:
        int frequency;
};

class Comparator
{
    public:
        int operator() ( const LeafNode& leafOne, const LeafNode& leafTwo );
};
