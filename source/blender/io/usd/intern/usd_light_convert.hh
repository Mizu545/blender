/* SPDX-FileCopyrightText: 2023 Blender Authors
 *
 * SPDX-License-Identifier: GPL-2.0-or-later */
#pragma once

#include <pxr/usd/usd/common.h>
#include <pxr/usd/usdLux/domeLight.h>

struct Main;
struct Scene;

namespace blender::io::usd {

struct USDExportParams;
struct USDImportParams;

/**
 * If the Blender scene has an environment texture,
 * export it as a USD dome light.
 */
void world_material_to_dome_light(const USDExportParams &params,
                                  const Scene *scene,
                                  pxr::UsdStageRefPtr stage);

void dome_light_to_world_material(const USDImportParams &params,
                                  Scene *scene,
                                  Main *bmain,
                                  const pxr::UsdLuxDomeLight &dome_light,
                                  const double motionSampleTime = 0.0);

}  // namespace blender::io::usd
