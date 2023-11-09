class Solution {
public:
        int minOperations(std::vector<std::string>& logs) {
        int depth = 0; // Represents the depth of the current folder
        
        for (const auto& log : logs) {
            if (log == "../") {
                if (depth > 0) {
                    depth--;
                }
            } else if (log != "./") {
                depth++;
            }
        }
        
        return depth;
    }
    
};