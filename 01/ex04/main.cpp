/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarros <fbarros@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 19:21:37 by fbarros           #+#    #+#             */
/*   Updated: 2022/05/25 14:27:53 by fbarros          ###   ########.fr       */
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

string    strReplace(string& dest, const string& src, size_t index)
{
    
}

std::string search(string& line, const string& original, const string& replace)
{
    // loop through line
    size_t i = tmp.find(original, 0);
    buffer += tmp.substr(0, i);
    if (i != tmp.npos)
        tmp = strReplace(tmp, replace, i);
    else
        i = tmp.length();
    buffer += tmp + "\n";
}

/* Return buffer */
std::string    scan(std::ifstream& fin, std::ofstream& fout, const string& original, const string& replace)
{
    string  buffer;
    string  tmp;

    while(!fin.eof()) {
        getline(fin, tmp);
        fout << search();
    }
    // fout << scan(fin, s1, s2);
    return buffer;
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
