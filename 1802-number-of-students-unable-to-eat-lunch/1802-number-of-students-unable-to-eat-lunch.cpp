class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int count[2] = {0}; // Count of students preferring square (count[1]) and circular (count[0]) sandwiches

        for (int student : students) {
            count[student]++; // Count the students' preferences
        }

        for (int sandwich : sandwiches) {
            if (count[sandwich] > 0) {
                count[sandwich]--; // If there is a sandwich of current type, a student will eat it
            } else {
                // No students left who prefer this type of sandwich
                return count[0] + count[1]; // Return the sum of remaining preferences
            }
        }

        return 0; // All students have eaten, return 0
    }
};
