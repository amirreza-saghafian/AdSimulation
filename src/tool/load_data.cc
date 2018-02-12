//
// Created by Amirreza Saghafian on 2/11/18.
//

#include "load_data.h"

#include <iostream>
#include <fstream>
#include <sstream>

std::vector<Item> LoadData::LoadItems(const std::string& item_file) const {
  std::vector<Item> items;
  std::vector<std::vector<std::string>> data = LoadText(item_file);

  for (const auto& line : data) {
    if (line.size() != 3) {
      throw std::invalid_argument("LoadData::LoadItems(): "
                                      "each item_ must have 3 tokens!");
    }

    items.emplace_back(Item{line[0], line[1], std::stod(line[2])});
  }

  return items;
}

std::vector<std::vector<std::string>> LoadData::LoadText(
    const std::string& data_file) const {
  std::vector<std::vector<std::string>> text;
  std::ifstream file(data_file);

  if (file.is_open()) {
    std::string line;

    while (getline(file, line)) {
      std::vector<std::string> tokens;
      std::string buff;
      std::stringstream ss(line);

      while (ss >> buff) {
        tokens.emplace_back(buff);
      }

      text.emplace_back(tokens);
    }
  }

  return text;
}