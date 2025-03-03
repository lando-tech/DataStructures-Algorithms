#include <memory>


class BinaryNode
{
    private:
        BinaryNode *parent{nullptr};
        std::unique_ptr<BinaryNode> m_left{};
        std::unique_ptr<BinaryNode> m_right{};

    public:
        void left(std::unique_ptr<BinaryNode> child);
        void right(std::unique_ptr<BinaryNode> child);
};

class Node : BinaryNode
{
    public:
        Node(char character, int frequency);
        char getChar();
        int getFrequency() const;
    private:
        int frequency{};
        char character{};
};

class Comparator
{
    public:
        int operator() ( const Node& leafOne, const Node& leafTwo );
};
