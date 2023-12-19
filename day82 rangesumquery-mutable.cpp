class NumArray {
public:
    NumArray(std::vector<int>& nums) {
        n = nums.size();
        if (n > 0) {
            tree.resize(2 * n);
            buildTree(nums);
        }
    }

    void update(int index, int val) {
        index += n;
        tree[index] = val;

        while (index > 0) {
            int left = index;
            int right = index;

            if (index % 2 == 0) {
                right = index + 1;
            } else {
                left = index - 1;
            }

            tree[index / 2] = tree[left] + tree[right];
            index /= 2;
        }
    }

    int sumRange(int left, int right) {
        left += n;
        right += n;
        int sum = 0;

        while (left <= right) {
            if (left % 2 == 1) {
                sum += tree[left];
                left++;
            }

            if (right % 2 == 0) {
                sum += tree[right];
                right--;
            }

            left /= 2;
            right /= 2;
        }

        return sum;
    }

private:
    int n;
    std::vector<int> tree;

    void buildTree(const std::vector<int>& nums) {
        for (int i = 0; i < n; ++i) {
            tree[n + i] = nums[i];
        }

        for (int i = n - 1; i > 0; --i) {
            tree[i] = tree[2 * i] + tree[2 * i + 1];
        }
    }
};
