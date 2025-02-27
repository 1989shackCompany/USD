//
// Copyright 2022 Pixar
//
// Licensed under the Apache License, Version 2.0 (the "Apache License")
// with the following modification; you may not use this file except in
// compliance with the Apache License and the following modification to it:
// Section 6. Trademarks. is deleted and replaced with:
//
// 6. Trademarks. This License does not grant permission to use the trade
//    names, trademarks, service marks, or product names of the Licensor
//    and its affiliates, except as required to comply with Section 4(c) of
//    the License and to reproduce the content of the NOTICE file.
//
// You may obtain a copy of the Apache License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the Apache License with the above modification is
// distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
// KIND, either express or implied. See the Apache License for the specific
// language governing permissions and limitations under the Apache License.
//

#ifndef PXR_USD_IMAGING_USD_IMAGING_DATA_SOURCE_CAMERA_H
#define PXR_USD_IMAGING_USD_IMAGING_DATA_SOURCE_CAMERA_H

#include "pxr/usdImaging/usdImaging/dataSourcePrim.h"
#include "pxr/usdImaging/usdImaging/dataSourceStageGlobals.h"

#include "pxr/usd/usdGeom/camera.h"

#include "pxr/imaging/hd/dataSource.h"

PXR_NAMESPACE_OPEN_SCOPE


/// \class UsdImagingDataSourceCamera
///
/// A container data source representing camera info
///
class UsdImagingDataSourceCamera : public HdContainerDataSource
{
public:
    HD_DECLARE_DATASOURCE(UsdImagingDataSourceCamera);

    bool Has(const TfToken &name) override;
    TfTokenVector GetNames() override;
    HdDataSourceBaseHandle Get(const TfToken &name) override;

private:

    // Private constructor, use static New() instead.
    UsdImagingDataSourceCamera(
            const SdfPath &sceneIndexPath,
            UsdGeomCamera usdCamera,
            const UsdImagingDataSourceStageGlobals &stageGlobals);

private:
    const SdfPath _sceneIndexPath;
    UsdGeomCamera _usdCamera;
    const UsdImagingDataSourceStageGlobals & _stageGlobals;
};

HD_DECLARE_DATASOURCE_HANDLES(UsdImagingDataSourceCamera);

/// \class UsdImagingDataSourceCameraPrim
///
/// A prim data source representing UsdCamera.
///
class UsdImagingDataSourceCameraPrim : public UsdImagingDataSourcePrim
{
public:
    HD_DECLARE_DATASOURCE(UsdImagingDataSourceCameraPrim);

    bool Has(const TfToken &name) override;
    TfTokenVector GetNames() override;
    HdDataSourceBaseHandle Get(const TfToken &name) override;

private:

    // Private constructor, use static New() instead.
    UsdImagingDataSourceCameraPrim(
        const SdfPath &sceneIndexPath,
        UsdPrim usdPrim,
        const UsdImagingDataSourceStageGlobals &stageGlobals);
};

HD_DECLARE_DATASOURCE_HANDLES(UsdImagingDataSourceCameraPrim);

PXR_NAMESPACE_CLOSE_SCOPE

#endif // PXR_USD_IMAGING_USD_IMAGING_DATA_SOURCE_CAMERA_H
