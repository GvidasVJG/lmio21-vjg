#include <iostream>
#include <vector>
#include <map>

using namespace std;

// op=1 -> - op
// op>1 -> / op
// 11: cost=1, form=1, op=1, mask=10
bool transform(int value, int op, int digits_mask, int& result) {
    // Extract digits of interest.
    int d = value % digits_mask;
    int r = value / digits_mask;
    // Check that resulting number of digits is valid.
    if (d * 10 < digits_mask) {
        return false;
    }
    // Apply operation.
    if (op == 1) {
        if (d == 0 || d > 10) return false;
        d -= 1;
    } else {
        if (d % op != 0 || d / op >= 10) return false;
        d /= op;
    }
    // Reconstitute the result.
    // Note that 'd' is always a single digit at this point.
    result = r * 10 + d;
    return true;
}

void update_cost(vector<int>& queue, map<int, int>& cost,
                 int value, int op, int digits_mask) {
    int result = 0;
    if (transform(value, op, digits_mask, result)) {
        int c = op == 1 ? 1 : 2;
        if (cost.find(result) == cost.end() ||
            cost[result] > cost[value] + c) {
            cost[result] = cost[value] + c;
            queue.push_back(result);
        }
    }
}

int main() {
    int A;
    cin >> A;

    vector<int> queue = { A };
    map<int, int> cost = {{A, 0}};

    for (int i = 0; i < queue.size(); i++) {
        // Try all possible combinations.
        for (int op = 1; op <= 9; op++) {
            update_cost(queue, cost, queue[i], op, 10);
            update_cost(queue, cost, queue[i], op, 100);
        }
    }

    // Print answers.
    if (cost.find(1) == cost.end()) {
        cout << -1 << endl;
    } else {
        cout << cost[1] << endl;
    }
    return 0;
}

