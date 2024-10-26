#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <utility>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <chrono>
#include <thread>
using namespace std;
const string RESET = "\033[0m";
const string RED = "\033[31m";
const string GREEN = "\033[32m";
const string YELLOW = "\033[33m";
const string BLUE = "\033[34m";
const string MAGENTA = "\033[35m";
const string CYAN = "\033[36m";
const string WHITE = "\033[37m";
string block_choice;
int score = 0;
//works
class blocks {
public:
    vector<pair<int, int>> block_layer;
    string name;
};
void initialize_random() {
    srand(static_cast<unsigned int>(time(0)));
}

string random_block_generator(blocks& I_block, blocks& O_block, blocks& S_block, blocks& Z_block, blocks& L_block, blocks& J_block, blocks& T_block) {
    vector<string> block_names = {I_block.name, O_block.name, S_block.name, Z_block.name, L_block.name, J_block.name, T_block.name};
    return block_names[rand() % block_names.size()]; // Randomly select a block
}

void clearConsole() {
    cout << "\033[2J\033[1;1H"; 
}
void custom_print(string variable) {
    cout << "-" << variable << '\n';
}
void show_map(int Gridlayer[12][12]) {
    for (int row = 1; row < 11; row++) {
        for (int column = 1; column < 11; column++) {
            if (Gridlayer[row][column] == 1) {
                cout << "1 "; // Show filled blocks as '1'
            } else {
                cout << ". "; // Replace zero with '.'
            }
        }
        cout << '\n';
    }
}

void show_preview(int block_preview[4][4], blocks& I_block, blocks& O_block, blocks& S_block, blocks& Z_block, blocks& L_block, blocks& J_block, blocks& T_block) {
    
    clearConsole();
    // Generate the future block
    block_choice = random_block_generator(I_block, O_block, S_block, Z_block, L_block, J_block, T_block);
    
    // Clear the block_preview
    for (int row = 0; row < 3; row++) {
        for (int column = 0; column < 3; column++) {
            block_preview[row][column] = 0; 
        }
    }

    
    if (block_choice == "I") {
        block_preview[0][1] = 1;
        block_preview[1][1] = 1;
        block_preview[2][1] = 1;
        block_preview[1][0] = 1; 
        block_preview[1][2] = 1; 
    }
    else if (block_choice == "O") {
        block_preview[1][1] = 1;
        block_preview[1][2] = 1;
        block_preview[2][1] = 1;
        block_preview[2][2] = 1;
    }
    else if (block_choice == "L") {
        block_preview[1][1] = 1;
        block_preview[2][1] = 1;
        block_preview[2][2] = 1;
        block_preview[1][2] = 1; // Adjusting to fit in 3x3
    }
    else if (block_choice == "J") {
        block_preview[1][2] = 1;
        block_preview[2][2] = 1;
        block_preview[2][1] = 1;
        block_preview[1][1] = 1; // Adjusting to fit in 3x3
    }
    else if (block_choice == "S") {
        block_preview[1][1] = 1;
        block_preview[1][2] = 1;
        block_preview[2][1] = 1;
        block_preview[2][2] = 1; // Adjusting to fit in 3x3
    }
    else if (block_choice == "Z") {
        block_preview[1][1] = 1;
        block_preview[1][2] = 1;
        block_preview[2][1] = 1;
        block_preview[2][2] = 1; // Adjusting to fit in 3x3
    }
    else if (block_choice == "T") {
        block_preview[1][1] = 1;
        block_preview[1][2] = 1;
        block_preview[1][0] = 1; // Adjusting to fit in 3x3
        block_preview[2][1] = 1; // Adjusting to fit in 3x3
    }

    // Display the block preview
    cout << "Next Block Preview:\n";
    for (int row = 0; row < 3; row++) {
        for (int column = 0; column < 3; column++) {
            if (block_preview[row][column] != 0) {
                cout << block_preview[row][column] << ' ';
            } else {
                cout << ". "; 
            }
        }
        cout << '\n';
    }
}



void make_block_appear(int Gridlayer[12][12], blocks& I_block, blocks& O_block, blocks& S_block, blocks& Z_block, blocks& L_block, blocks& J_block, blocks& T_block, vector<pair<int, int>>& temp_layer) {
    // Generate the current block
    string block_choice = random_block_generator(I_block, O_block, S_block, Z_block, L_block, J_block, T_block);
    temp_layer.clear();

    // Place the block based on present_block
    if (block_choice == "I") {
        for (auto& pos : I_block.block_layer) { 
            if (pos.first >= 0 && pos.first < 12 && pos.second >= 0 && pos.second < 12) {
                Gridlayer[pos.first][pos.second] = 1;
            }
        }
        temp_layer = I_block.block_layer;
    }
    else if (block_choice == "O") {
        for (auto& pos : O_block.block_layer) { 
            if (pos.first >= 0 && pos.first < 12 && pos.second >= 0 && pos.second < 12) {
                Gridlayer[pos.first][pos.second] = 1;
            }
        }
        temp_layer = O_block.block_layer;
    }
    else if (block_choice == "L") {
        for (auto& pos : L_block.block_layer) { 
            if (pos.first >= 0 && pos.first < 12 && pos.second >= 0 && pos.second < 12) {
                Gridlayer[pos.first][pos.second] = 1;
            }
        }
        temp_layer = L_block.block_layer;
    }
    else if (block_choice == "J") {
        for (auto& pos : J_block.block_layer) { 
            if (pos.first >= 0 && pos.first < 12 && pos.second >= 0 && pos.second < 12) {
                Gridlayer[pos.first][pos.second] = 1;
            }
        }
        temp_layer = J_block.block_layer;
    }
    else if (block_choice == "S") {
        for (auto& pos : S_block.block_layer) { 
            if (pos.first >= 0 && pos.first < 12 && pos.second >= 0 && pos.second < 12) {
                Gridlayer[pos.first][pos.second] = 1;
            }
        }
        temp_layer = S_block.block_layer;
    }
    else if (block_choice == "Z") {
        for (auto& pos : Z_block.block_layer) { 
            if (pos.first >= 0 && pos.first < 12 && pos.second >= 0 && pos.second < 12) {
                Gridlayer[pos.first][pos.second] = 1;
            }
        }
        temp_layer = Z_block.block_layer;
    }
    else if (block_choice == "T") {
        for (auto& pos : T_block.block_layer) { 
            if (pos.first >= 0 && pos.first < 12 && pos.second >= 0 && pos.second < 12) {
                Gridlayer[pos.first][pos.second] = 1;
            }
        }
        temp_layer = T_block.block_layer;
    }

   
}


string check_if_out_of_bound(vector<pair<int, int>>& temp_layer) {
    for(auto& pos : temp_layer) {
        if (pos.second == 11) { // Right boundary
            return "right_bound";
        } 
        else if (pos.second == 0) { // Left boundary
            return "left_bound";
        }
    }
    return " ";
}
void OutOfBoundaries(int Gridlayer[12][12], vector<pair<int, int>>& temp_layer) {
    string boundary = check_if_out_of_bound(temp_layer);
    for(auto& pos : temp_layer) {
        if (boundary == "right_bound") {
            pos.second -= 1;
        } 
        else if (boundary == "left_bound") { 
            pos.second += 1;
        }
    }
}
vector<pair<int, int>> boundary(vector<pair<int, int>>& temp_layer, int Gridlayer[12][12]) {
    vector<pair<int, int>> boundary_vec;

    auto is_part_of_block = [&](int x, int y) {
        for (const auto& pos : temp_layer) {
            if (pos.first == x && pos.second == y) {
                return true;
            }
        }
        return false;
    };

    for (const auto& pos : temp_layer) {
        int x = pos.first;
        int y = pos.second;

        if (x < 11 && !is_part_of_block(x + 1, y)) {
            boundary_vec.push_back(make_pair(x + 1, y));  
        }
    }

 


    return boundary_vec;
}


void rotation(int Gridlayer[12][12], vector<pair<int, int>>& temp_layer) {
    int center_X, center_Y;
    int min_X = numeric_limits<int>::max(); 
    int min_Y = numeric_limits<int>::max(); 
    int max_X = numeric_limits<int>::min();
    int max_Y = numeric_limits<int>::min();

   
    for (const auto& offset : temp_layer) {
        if (offset.first < min_X) {
            min_X = offset.first; 
        }
        if (offset.first > max_X) {
            max_X = offset.first; 
        }
        if (offset.second < min_Y) {
            min_Y = offset.second;
        }
        if (offset.second > max_Y) {
            max_Y = offset.second; 
        }
    }

   
    center_X = (min_X + max_X) / 2;
    center_Y = (min_Y + max_Y) / 2;

    
    for (auto& offset : temp_layer) {
        int oldX = offset.first;
        int oldY = offset.second;
        
        
        offset.first = center_X + (oldY - center_Y); 
        offset.second = center_Y - (oldX - center_X); 
    }
}





bool collision(int Gridlayer[12][12], vector<pair<int, int>>& temp_layer) {
    vector<pair<int, int>> boundary_positions = boundary(temp_layer, Gridlayer);
    for (const auto& pos : boundary_positions) {
        if (Gridlayer[pos.first][pos.second] == 1) {
            return false; 
        }
    }
    return true; 
}

void movement(string user_input, int Gridlayer[12][12], 
               blocks& I_block, blocks& O_block, blocks& S_block, 
               blocks& Z_block, blocks& L_block, blocks& J_block, 
               blocks& T_block, vector<pair<int, int>>& temp_layer) {
    
    // Clear old positions in the grid
    for (auto& pos : temp_layer) {
        if (pos.first >= 0 && pos.first < 12 && pos.second >= 0 && pos.second < 12) {
            Gridlayer[pos.first][pos.second] = 0;
        }
    }

    // Move down
    if (user_input == "s") {
        for (auto& off_set : temp_layer) {
            off_set.first += 1; 
            OutOfBoundaries(Gridlayer, temp_layer);
        }
    }
    // Move right
    else if (user_input == "d") {
        for (auto& off_set : temp_layer) {
            off_set.second += 1; 
            OutOfBoundaries(Gridlayer, temp_layer);
        }
    }
    // Move left
    else if (user_input == "q") {
        for (auto& off_set : temp_layer) {
            off_set.second -= 1; 
            OutOfBoundaries(Gridlayer, temp_layer);
        }
    }
    // Rotation
    else if (user_input == "r") {
        rotation(Gridlayer, temp_layer); 
        OutOfBoundaries(Gridlayer, temp_layer);
    }

    // Check for collisions with the updated positions in temp_layer
    if (collision(Gridlayer, temp_layer)) {
        // If no collision  then update the grid with new positions
        for (const auto& pos : temp_layer) {
            if (pos.first >= 0 && pos.first < 12 && pos.second >= 0 && pos.second < 12) {
                Gridlayer[pos.first][pos.second] = 1; // add new positions in grid
            }
        }
    } else {
        // Collision detected
        for (const auto& pos : temp_layer) {
            Gridlayer[pos.first][pos.second] = 1; // Keep current block in the grid
        }
        
        make_block_appear(Gridlayer, I_block, O_block, S_block, Z_block, L_block, J_block, T_block, temp_layer);
    }
}






bool isBlockOnGround(vector<pair<int, int>>& temp_layer, int Gridlayer[12][12]) {
   
    for (auto& pos : temp_layer) {
        if (pos.first == 10 ) {  
            return true;  
        }

    }
    if (!collision(Gridlayer, temp_layer)) {
        return false; 
    }
    return false; 
}
void displayScore() {
    cout << "Your current score is: " << score << "\n";
}

bool is_row_full(int Gridlayer[12][12], int& full_row) {
    for (int row = 10; row > 1; row--) {  
        int count_ones = 0; 
        for (int col = 1; col < 11; col++) {  
            if (Gridlayer[row][col] == 1) {
                count_ones++;
            }
        }
        if (count_ones == 10) { 
            full_row = row;
            score += 100; 
            return true;
        }       
    } 
    return false;
}

void destroy_row(int Gridlayer[12][12], vector<pair<int, int>>& temp_layer) {       
    int full_row; 
    while (is_row_full(Gridlayer, full_row)) {
        for (int row = full_row; row > 1; row--) {  
            for (int col = 1; col < 11; col++) {  
                Gridlayer[row][col] = Gridlayer[row - 1][col];
            }
        }
        
        for (int col = 1; col < 11; col++) {  
            Gridlayer[1][col] = 0;
        }
    }
    displayScore(); 
}
int main() {
    

    int Gridlayer[12][12] = {
        {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2},
        {2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},
        {2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},
        {2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},
        {2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},
        {2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},
        {2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},
        {2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},
        {2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},
        {2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},
        {2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},
        {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2}
    };
   int block_preview[4][4] = {
    {0,0,0,0},
    {0,0,0,0},
    {0,0,0,0},
    {0,0,0,0} };

    // initialize objects
    blocks I_block = { {{1, 1}, {2, 1}, {3, 1}, {4, 1}}, "I" };
    blocks O_block = { {{1, 1}, {1, 2}, {2, 1}, {2, 2}}, "O" };
    blocks T_block = { {{1, 1}, {1, 2}, {1, 3}, {2, 2}}, "T" };
    blocks L_block = { {{1, 1}, {2, 1}, {3, 1}, {3, 2}}, "L" };
    blocks J_block = { {{1, 2}, {2, 2}, {3, 2}, {3, 1}}, "J" };
    blocks S_block = { {{2, 1}, {2, 2}, {1, 2}, {1, 3}}, "S" };
    blocks Z_block = { {{1, 1}, {1, 2}, {2, 2}, {2, 3}}, "Z" };
    int full_row;
    vector<pair<int, int>> temp_layer;
    make_block_appear(Gridlayer, I_block, O_block, S_block, Z_block, L_block, J_block, T_block, temp_layer);
      while (true) {
        
        show_preview(block_preview,I_block, O_block, S_block, Z_block, L_block, J_block, T_block);
        show_map(Gridlayer);
        
        while (true) {
           
            if (temp_layer.empty() || !isBlockOnGround(temp_layer,Gridlayer)) {
                custom_print("where do you want to move");
                string user_input;
                cin >> user_input;

                movement(user_input,Gridlayer,I_block, O_block, S_block, Z_block, L_block, J_block, T_block,temp_layer);
                destroy_row(Gridlayer,temp_layer);
                show_preview(block_preview,I_block, O_block, S_block, Z_block, L_block, J_block, T_block);
                show_map(Gridlayer);
                displayScore();
                if ((user_input != "ù") && !collision(Gridlayer,temp_layer)) {
                    cout << "Game over";
                    displayScore();
                    return 1;
                }
                 
            }  
            else {
                make_block_appear(Gridlayer, I_block, O_block, S_block, Z_block, L_block, J_block, T_block, temp_layer);
            }
          
        }
    
    }

   

    return 0;
}
