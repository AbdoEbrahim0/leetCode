//i stil not understand the logic of problem but not worth to solve it any way  

class OrderedStream {
private:
    vector<string> stream;
    int ptr;
public:
    OrderedStream(int n) {
        stream.resize(n);
        ptr = 0;
    }

    vector<string> insert(int idKey, string value) {
        vector<string >temp;
        stream[idKey - 1] = value;
        while (ptr< stream.size() && !stream[ptr].empty())
        {
            temp.push_back(stream[ptr]);
                ptr++;
        }
        return temp;
    }
};