/**
 * Flc_Util.cpp
 *
 * EPCC, The University of Edinburgh
 *
 * (c) 2021 The University of Edinburgh
 *
 * Contributing Authors:
 * Christodoulos Stylianou (c.stylianou@ed.ac.uk)
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * 	http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <Morpheus_Core.hpp>
#include "Fcl_Util.h"

#include <iostream>
#include <fstream>
#include <cstdio>
#include <stddef.h>

extern "C" {

void c_morpheus_initialize(int* argc, char** argv) {
  Morpheus::initialize(*argc, argv);
}

void c_morpheus_initialize_without_args() { Morpheus::initialize(); }

void c_morpheus_finalize() { Kokkos::finalize(); }

void c_morpheus_print_configuration(const char* prepend_name_in,
                                    const char* file_name_in) {
  std::string prepend_name(prepend_name_in);
  std::string file_name(file_name_in);
  std::string output_filename = prepend_name + file_name;
  std::ofstream morpheus_output_file(output_filename);
  if (morpheus_output_file.is_open()) {
    Morpheus::print_configuration(morpheus_output_file, true);
    morpheus_output_file.close();
  } else {
    std::cout << "Could not open filename " << output_filename;
    std::cout << " to dump Morpheus::print_configuration to." << std::endl;
  }
}

}  // extern "C"