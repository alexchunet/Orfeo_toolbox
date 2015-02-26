#include "otbTestMain.h"
void RegisterTests()
{
  REGISTER_TEST(otbVectorImageToImageListFilter);
  REGISTER_TEST(otbVectorImageToImageListFilterIterator);
  REGISTER_TEST(otbBinaryImageDensityFunctionNew);
  REGISTER_TEST(otbPrintableImageFilter);
  REGISTER_TEST(otbConcatenateScalarValueImageFilterNew);
  REGISTER_TEST(otbConcatenateScalarValueImageFilterTest);
  REGISTER_TEST(otbDEMToImageGeneratorNew);
  REGISTER_TEST(otbShiftScaleImageAdaptor);
  REGISTER_TEST(otbImageToVectorImageCastFilter);
  REGISTER_TEST(otbFunctionWithNeighborhoodToImageFilter);
  REGISTER_TEST(otbSqrtSpectralAngleImageFilter);
  REGISTER_TEST(otbUnaryFunctorNeighborhoodImageFilterNew);
  REGISTER_TEST(otbStreamingShrinkImageFilter);
  REGISTER_TEST(otbUnaryFunctorWithIndexImageFilterNew);
  REGISTER_TEST(otbProlateInterpolateImageFunction);
  REGISTER_TEST(otbUnaryFunctorImageFilterNew);
  REGISTER_TEST(otbDEMToImageGeneratorTest);
  REGISTER_TEST(otbUnaryImageFunctorWithVectorImageFilter);
  REGISTER_TEST(otbImageToVectorImageCastFilterNew);
  REGISTER_TEST(otbPrintableImageFilterWithMask);
  REGISTER_TEST(otbStreamingResampleImageFilter);
  REGISTER_TEST(otbUnaryFunctorNeighborhoodWithOffsetImageFilterNew);
  REGISTER_TEST(otbBoxAndWhiskerImageFilterNew);
  REGISTER_TEST(otbVectorImageToAmplitudeImageFilter);
  REGISTER_TEST(otbUnaryFunctorNeighborhoodWithOffsetImageFilter);
  REGISTER_TEST(otbStreamingResampleImageFilterCompareWithITK);
  REGISTER_TEST(otbRegionProjectionResampler);
  REGISTER_TEST(otbVectorImageTo3DScalarImageFilterNew);
  REGISTER_TEST(otbUnaryFunctorWithIndexImageFilter);
  REGISTER_TEST(otbMeanFunctorImageTest);
  REGISTER_TEST(otbLocalActivityVectorImageFilterNewTest);
  REGISTER_TEST(otbLocalActivityVectorImageFilterTest);
  REGISTER_TEST(otbBinaryImageToDensityImageFilterNew);
  REGISTER_TEST(otbVectorImageTo3DScalarImageFilter);
  REGISTER_TEST(otbTileImageFilterNew);
  REGISTER_TEST(otbTileImageFilter);
  REGISTER_TEST(otbMatrixImageFilterNew);
  REGISTER_TEST(otbMatrixImageFilterTest);
  REGISTER_TEST(otbMatrixTransposeMatrixImageFilter);
  REGISTER_TEST(otbPerBandVectorImageFilterNew);
  REGISTER_TEST(otbInverseLogPolarTransformResample);
  REGISTER_TEST(otbUnaryFunctorNeighborhoodImageFilter);
  REGISTER_TEST(otbStreamingResampleImageFilterNew);
  REGISTER_TEST(otbStreamingInnerProductVectorImageFilter);
  REGISTER_TEST(otbPhaseFunctorTest);
  REGISTER_TEST(otbShiftScaleVectorImageFilterNew);
  REGISTER_TEST(otbChangeLabelImageFilter);
  REGISTER_TEST(otbVectorImageToImageListFilterNew);
  REGISTER_TEST(otbClampVectorImageFilterNew);
  REGISTER_TEST(otbClampVectorImageFilterTest);
  REGISTER_TEST(otbPrintableImageFilterNew);
  REGISTER_TEST(otbShiftScaleImageAdaptorNew);
  REGISTER_TEST(otbStreamingInnerProductVectorImageFilterNew);
  REGISTER_TEST(otbBCOInterpolateImageFunctionNew);
  REGISTER_TEST(otbBCOInterpolateImageFunction2);
  REGISTER_TEST(otbBCOInterpolateImageFunctionOverVectorImageNew);
  REGISTER_TEST(otbBCOInterpolateImageFunctionOverVectorImage);
  REGISTER_TEST(otbBCOInterpolateImageFunctionTest);
  REGISTER_TEST(otbBCOInterpolateImageFunctionVectorImageTest);
  REGISTER_TEST(otbImageToImageListFilterNew);
  REGISTER_TEST(otbDEMToImageGeneratorFromImageTest);
  REGISTER_TEST(otbBoxAndWhiskerImageFilter);
  REGISTER_TEST(otbStreamingShrinkImageFilterNew);
  REGISTER_TEST(otbVectorRescaleIntensityImageFilter);
  REGISTER_TEST(otbLog10ThresholdedImageFilterTest);
  REGISTER_TEST(otbChangeLabelImageFilterNew);
  REGISTER_TEST(otbInverseLogPolarTransformNew);
  REGISTER_TEST(otbStreamingResampleImageFilterWithAffineTransform);
  REGISTER_TEST(otbMatrixTransposeMatrixImageFilterNew);
  REGISTER_TEST(otbExtractROIResample);
  REGISTER_TEST(otbLocalGradientVectorImageFilterNewTest);
  REGISTER_TEST(otbLocalGradientVectorImageFilterTest);
  REGISTER_TEST(otbBinaryImageMinimalBoundingRegionCalculator);
  REGISTER_TEST(otbPerBandVectorImageFilterWithSobelFilter);
  REGISTER_TEST(otbProlateValidationTest);
  REGISTER_TEST(otbBinaryImageDensityFunction);
  REGISTER_TEST(otbVectorImageToAmplitudeImageFilterNew);
  REGISTER_TEST(otbThresholdVectorImageFilterNew);
  REGISTER_TEST(otbThresholdVectorImageFilterTest);
  REGISTER_TEST(otbPerBandVectorImageFilterWithMeanFilter);
  REGISTER_TEST(otbConcatenateVectorImageFilterNew);
  REGISTER_TEST(otbAmplitudeFunctorTest);
  REGISTER_TEST(otbMultiplyByScalarImageFilterTest);
  REGISTER_TEST(otbClampImageFilterNew);
  REGISTER_TEST(otbClampImageFilterTest);
  REGISTER_TEST(otbConcatenateVectorImageFilter);
  REGISTER_TEST(otbBinaryImageMinimalBoundingRegionCalculatorNew);
  REGISTER_TEST(otbVectorRescaleIntensityImageFilterNew);
  REGISTER_TEST(otbSpectralAngleDistanceImageFilterNew);
  REGISTER_TEST(otbUnaryImageFunctorWithVectorImageFilterNew);
  REGISTER_TEST(otbBinaryImageToDensityImageFilter);
  REGISTER_TEST(otbInverseLogPolarTransform);
  REGISTER_TEST(otbSpectralAngleDistanceImageFilter);
  REGISTER_TEST(otbFunctionWithNeighborhoodToImageFilterNew);
  REGISTER_TEST(otbEuclideanDistanceMetricWithMissingValue);
  REGISTER_TEST(otbEuclideanDistanceMetricWithMissingValueNew);
}
