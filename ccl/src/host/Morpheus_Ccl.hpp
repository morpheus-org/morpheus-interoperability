/**
 * Morpheus_Ccl.hpp
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

#ifndef MORPHEUS_CCL_HOST_HPP
#define MORPHEUS_CCL_HOST_HPP

#include <host/Morpheus_Ccl_CooMatrix.hpp>
#include <host/Morpheus_Ccl_CsrMatrix.hpp>
#include <host/Morpheus_Ccl_DiaMatrix.hpp>
#include <host/Morpheus_Ccl_DenseVector.hpp>
#include <host/Morpheus_Ccl_DynamicMatrix.hpp>

#include <host/Morpheus_Ccl_MirrorContainers.hpp>

#include <host/Morpheus_Ccl_Convert.hpp>
#include <host/Morpheus_Ccl_Copy.hpp>
#include <host/Morpheus_Ccl_Dot.hpp>
#include <host/Morpheus_Ccl_Multiply.hpp>
#include <host/Morpheus_Ccl_Print.hpp>
#include <host/Morpheus_Ccl_Reduction.hpp>
#include <host/Morpheus_Ccl_Scan.hpp>
#include <host/Morpheus_Ccl_WAXPBY.hpp>

#endif  // MORPHEUS_CCL_HOST_HPP