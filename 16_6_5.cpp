#include <iostream>

bool check(std::string str) {
    std::string white_list = "XO.";
    if (str.length() != 3) return false;
    for (int i = 0; i < 3; i++) {
        if (white_list.find(str[i]) == -1) return false;
    }
    return true;
}

char get_symbol(int line, int index, std::string str) {
    return (str[line * 3 + index]);
}

int who_win_line(int line_index, std::string str) {
    if ((get_symbol(line_index, 0, str) == get_symbol(line_index, 1, str)) &&
        (get_symbol(line_index, 0, str) == get_symbol(line_index, 2, str))) {
        if (get_symbol(line_index, 0, str) == 'X') return 1;
        else if (get_symbol(line_index, 0, str) == 'O') return 2;
        else return 3;
    }
}

int who_win_column(int column_index, std::string str) {
    if ((get_symbol(0, column_index, str) == get_symbol(1, column_index, str)) &&
        (get_symbol(1, column_index, str) == get_symbol(2, column_index, str))) {
        if (get_symbol(0, column_index, str) == 'X') return 1;
        else if (get_symbol(0, column_index, str) == 'O') return 2;
        else return 3;
    }
}

int who_win_diagonal(int diagonal_index, std::string str) {
    if (diagonal_index == 1) {
        if ((get_symbol(0, 0, str) == get_symbol(1, 1, str)) && (get_symbol(0, 0, str) == get_symbol(2, 2, str))) {
            if (get_symbol(0, 0, str) == 'X') return 1;
            else if (get_symbol(0, 0, str) == 'O') return 2;
            else return 3;
        }
    } else if (diagonal_index == 2) {
        if ((get_symbol(0, 2, str) == get_symbol(1, 1, str)) && (get_symbol(0, 2, str) == get_symbol(2, 0, str))) {
            if (get_symbol(0, 2, str) == 'X') return 1;
            else if (get_symbol(0, 2, str) == 'O') return 2;
            else return 3;
        }
    }
    return 3;
}

int main() {
    std::string line_1, line_2, line_3;
    std::cout << "Input the first line:" << std::endl;
    std::cin >> line_1;
    std::cout << "Input the second line:" << std::endl;
    std::cin >> line_2;
    std::cout << "Input the third line:" << std::endl;
    std::cin >> line_3;

    if (!(check(line_1) && check(line_2) && check(line_3))) {
        std::cout << "\nWrong input!" << std::endl;
        return 0;
    }

    std::string line = line_1 + line_2 + line_3;
    int x_wins, o_wins;
    x_wins = o_wins = 0;

    for (int i = 0; i < 3; i++) {
        if (who_win_line(i, line) == 1) x_wins++;
        else if (who_win_line(i, line) == 2) o_wins++;
        if (who_win_column(i, line) == 1) x_wins++;
        else if (who_win_column(i, line) == 2) o_wins++;
        if (who_win_diagonal(i, line) == 1) x_wins++;
        else if (who_win_diagonal(i, line) == 2) o_wins++;
    }

    int o_counter, x_counter;
    o_counter = x_counter = 0;
    for (int i = 0; i < 9; i++) {
        if (line[i] == 'X') x_counter++;
        else if (line[i] == 'O') o_counter++;
    }
    if (x_counter < o_counter) std::cout << "Incorrect!1";
    else if ((x_wins + o_wins) == 0) std::cout << "Nobody!";
    else if ((x_wins + o_wins) != 1) std::cout << "Incorrect!2";
    else if (x_wins == 1 && (x_counter <= o_counter)) std::cout << "Incorrect!3";
    else if (o_wins == 1 && (x_counter > o_counter)) std::cout << "Incorrect!4";
    else if ((x_wins + o_wins) > 1) std::cout << "Incorrect!5";
    else if (x_wins == 1) std::cout << "Petya won!";
    else if (o_wins == 1) std::cout << "Vasya won!";
}
