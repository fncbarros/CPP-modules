/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarros <fbarros@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 19:21:37 by fbarros           #+#    #+#             */
/*   Updated: 2022/05/25 17:40:36 by fbarros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <fstream>

using	std::string;
using	std::cout;
using	std::cin;
using	std::endl;

std::string search(string& line, const string& original, const string& replace)
/* substr() & find() */
{
    string  buffer;
    size_t  orig_pos = 0;
    size_t  last_orig_pos;

    while (orig_pos != line.npos) {
        last_orig_pos = orig_pos;
        orig_pos = line.find(original, orig_pos);
        buffer += line.substr(last_orig_pos, orig_pos);
        if (orig_pos != line.npos) {
            buffer += replace;
            orig_pos += original.length();
        }
    }
    buffer += "\n";
    return buffer;
}

/* Return buffer */
void    scan(std::ifstream& fin, std::ofstream& fout, const string& original, const string& replace)
{
    string  buffer;

    while(!fin.eof()) {
        getline(fin, buffer);
        fout << search(buffer, original, replace);
    }
}

int main(int argc, char **argv)
{
    if (argc != 4) {
        std::cerr << "Not enough arguments\n";
        return 1;
    }
    string filename = argv[1], s1 = argv[2], s2 = argv[3];
    std::ofstream   fout;
    std::ifstream   fin;

    fin.open(filename.c_str(), std::ios::in);
    if (!fin) {
        std::cerr << "File error.\n";
        return 1;
    }
    string outfile = filename + ".replace";
    fout.open(outfile.c_str(), std::ios::out | std::ios::app);
    if (!fout) {
        std::cerr << "File error.\n";
        fin.close();
        return 1;
    }
    scan(fin, fout, s1, s2);
    fin.close();
    fout.close();
    return 0;
}
