/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileReplacer.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 10:28:00 by cado-car          #+#    #+#             */
/*   Updated: 2023/07/04 15:40:22 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FileReplacer.hpp"

// Constructor
FileReplacer::FileReplacer(const std::string& filename, const std::string& s1, const std::string& s2): 
	_filename(filename), 
	_search_string(s1), 
	_replacement_string(s2) 
{
	// Open file
	std::ifstream input_file(filename.c_str());
	if (!input_file.is_open()) {
		throw std::runtime_error(RED + "Error opening file." + RESET);
	}

	// Create output file
	std::string new_filename = filename;
	std::string suffix = ".replace";
	_output_file.open(new_filename.append(suffix).c_str());
	if (!_output_file.is_open()) {
		input_file.close();
		throw std::runtime_error(RED + "Error creating output file." + RESET);
	}

	// Read file line by line
	std::string line;
	while (std::getline(input_file, line)) {
		_replace(line);
		if (!input_file.eof()) {
			_output_file << std::endl;
		}
	}

	input_file.close();
	_output_file.close();
}

// Destructor
FileReplacer::~FileReplacer(void) {
	return ;
}

// Private method
void FileReplacer::_replace(const std::string& line) {
	size_t	start_pos = 0;
	size_t	found_pos = line.find(_search_string, start_pos);

	// Get all occurrences of the search string in line and replace them
	while (found_pos != std::string::npos) {
		_output_file << line.substr(start_pos, found_pos - start_pos) << _replacement_string;
		start_pos = found_pos + _search_string.length();
		found_pos = line.find(_search_string, start_pos);
	}
	// Write the rest of the line
	_output_file << line.substr(start_pos, found_pos - start_pos);
}
