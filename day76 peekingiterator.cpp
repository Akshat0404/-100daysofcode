class Iterator {
public:
    explicit Iterator(const std::vector<int>& nums) : data(nums), index(0) {}

    int next() {
        return data[index++];
    }

    bool hasNext() const {
        return index < data.size();
    }

private:
    const std::vector<int>& data;
    size_t index;
};

class PeekingIterator : public Iterator {
public:
    PeekingIterator(const std::vector<int>& nums) : Iterator(nums), hasPeeked(false) {}

    int peek() {
        if (!hasPeeked) {
            peekedElement = Iterator::next();
            hasPeeked = true;
        }
        return peekedElement;
    }

    int next() {
        if (!hasPeeked) {
            return Iterator::next();
        }
        hasPeeked = false;
        return peekedElement;
    }

    bool hasNext() const {
        return hasPeeked || Iterator::hasNext();
    }

private:
    bool hasPeeked;
    int peekedElement;
};
