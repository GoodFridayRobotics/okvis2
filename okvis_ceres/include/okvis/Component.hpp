/*********************************************************************************
 *  OKVIS - Open Keyframe-based Visual-Inertial SLAM
 *  Copyright (c) 2015, Autonomous Systems Lab / ETH Zurich
 *  Copyright (c) 2020, Smart Robotics Lab / Imperial College London
 *  Copyright (c) 2024, Smart Robotics Lab / Technical University of Munich
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions are met:
 *
 *   * Redistributions of source code must retain the above copyright notice,
 *     this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above copyright notice,
 *     this list of conditions and the following disclaimer in the documentation
 *     and/or other materials provided with the distribution.
 *   * Neither the name of Autonomous Systems Lab, ETH Zurich, Smart Robotics Lab,
 *     Imperial College London, Technical University of Munich, nor the names of
 *     its contributors may be used to endorse or promote products derived from
 *     this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 *  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 *  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 *  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 *  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 *  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 *  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 *  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 *  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 *  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 *  POSSIBILITY OF SUCH DAMAGE.
 *********************************************************************************/

/**
 * @file okvis/Component.hpp
 * @brief Header file for the Component class. Load/save/multisession stuff.
 * @author Stefan Leutenegger
 */

#ifndef INCLUDE_OKVIS_COMPONENT_HPP_
#define INCLUDE_OKVIS_COMPONENT_HPP_

#include <okvis/ViGraphEstimator.hpp>

/// \brief okvis Main namespace of this package.
namespace okvis {

/// \brief Class containing a SLAM run.
class Component
{
  public:
  OKVIS_DEFINE_EXCEPTION(Exception, std::runtime_error)
  EIGEN_MAKE_ALIGNED_OPERATOR_NEW

  /// \brief Constructor with graph and frames
  Component(const ImuParameters &imuParameters,
            const cameras::NCameraSystem& nCameraSystem,
            ViGraphEstimator &fullGraph,
            std::map<StateId, MultiFramePtr> multiFrames);

  /// \brief Default constructor
  Component(const ImuParameters &imuParameters, const cameras::NCameraSystem& nCameraSystem);

  /// \brief Load this component.
  /// \return True on success.
  bool load(const std::string &path);

  /// \brief Save this component.
  /// \return True on success.
  bool save(const std::string &path);

  //private:
  ImuParameters imuParameters_; ///< IMU parameters of this Component.
  cameras::NCameraSystem nCameraSystem_; ///< Multi-camera configuration of this Component.
  ViGraphEstimator *fullGraph_ = nullptr; ///< The full graoh for asynchronous optimisation.
  std::unique_ptr<ViGraphEstimator> fullGraphOwn_; ///< Owned full graph.
  std::map<StateId, MultiFramePtr> multiFrames_; ///< All the multiframes added so far.
};

}  // namespace okvis

#endif /* INCLUDE_OKVIS_COMPONENT_HPP_ */
