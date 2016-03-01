/*=========================================================================

  Program:   ORFEO Toolbox
  Language:  C++
  Date:      $Date$
  Version:   $Revision$


  Copyright (c) Centre National d'Etudes Spatiales. All rights reserved.
  See OTBCopyright.txt for details.


     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notices for more information.

=========================================================================*/
#ifndef __otbOGRDataToResampledOGRData_h
#define __otbOGRDataToResampledOGRData_h

#include "otbPersistentImageFilter.h"
#include "otbPersistentFilterStreamingDecorator.h"
#include "otbOGRDataSourceWrapper.h"
#include "otbOGRDataResampler.h"
#include "itkSimpleDataObjectDecorator.h"

namespace otb
{

/**
 * \class PersistentOGRDataToResampledOGRData
 * 
 * \brief Persistent filter to compute class statistics based on vectors
 * 
 */
template<class TInputImage, class TMaskImage>
class ITK_EXPORT PersistentOGRDataToResampledOGRData :
  public PersistentImageFilter<TInputImage, TInputImage>
{
public:
  /** Standard Self typedef */
  typedef PersistentOGRDataToResampledOGRData        Self;
  typedef PersistentImageFilter<TInputImage, TInputImage> Superclass;
  typedef itk::SmartPointer<Self>                         Pointer;
  typedef itk::SmartPointer<const Self>                   ConstPointer;

  typedef TInputImage                                     InputImageType;
  typedef typename InputImageType::Pointer                InputImagePointer;
  typedef typename InputImageType::RegionType             RegionType;
  typedef typename InputImageType::PointType              PointType;

  typedef TMaskImage                                      MaskImageType;
  typedef typename MaskImageType::Pointer                 MaskImagePointer;

  typedef otb::ogr::DataSource                            OGRDataType;
  typedef otb::ogr::DataSource::Pointer                   OGRDataPointer;

  typedef otb::OGRDataResampler::ClassCountMapType   ClassCountMapType;
  typedef otb::OGRDataResampler::PolygonSizeMapType  PolygonSizeMapType;

  /** Wrap output type as DataObject */
  typedef itk::SimpleDataObjectDecorator<ClassCountMapType>  ClassCountObjectType;
  typedef itk::SimpleDataObjectDecorator<PolygonSizeMapType> PolygonSizeObjectType;

  typedef itk::DataObject::DataObjectPointerArraySizeType DataObjectPointerArraySizeType;

  /** Method for creation through the object factory. */
  itkNewMacro(Self);

  /** Runtime information support. */
  itkTypeMacro(PersistentOGRDataToResampledOGRData, PersistentImageFilter);

  void SetOGRData(const otb::ogr::DataSource* vector);
  const otb::ogr::DataSource* GetOGRData();

  void SetMask(const TMaskImage* mask);
  const TMaskImage* GetMask();

  void Synthetize(void);

  /** Reset method called before starting the streaming*/
  void Reset(void);

  // TODO : prevent loading of data into output

  itkSetMacro(FieldName, std::string);
  itkGetMacro(FieldName, std::string);
  
  itkSetMacro(LayerIndex, int);
  itkGetMacro(LayerIndex, int);

  // TODO: store the class count map as output #2
  const ClassCountObjectType* GetClassCountOutput() const;
  ClassCountObjectType* GetClassCountOutput();

  // TODO: store the polygon size map as output #3
  const PolygonSizeObjectType* GetPolygonSizeOutput() const;
  PolygonSizeObjectType* GetPolygonSizeOutput();

  /** Make a DataObject of the correct type to be used as the specified
   * output. */
  virtual itk::DataObject::Pointer MakeOutput(DataObjectPointerArraySizeType idx);
  using Superclass::MakeOutput;

protected:
  /** Constructor */
  PersistentOGRDataToResampledOGRData();
  /** Destructor */
  virtual ~PersistentOGRDataToResampledOGRData() {}

  virtual void GenerateOutputInformation();

  virtual void GenerateInputRequestedRegion();

  //virtual void BeforeThreadedGenerateData();

  //virtual void ThreadedGenerateData(const RegionType& outputRegionForThread,
  //                                  itk::ThreadIdType threadId);
  virtual void GenerateData();

private:
  PersistentOGRDataToResampledOGRData(const Self &); //purposely not implemented
  void operator =(const Self&); //purposely not implemented

  void ApplyPolygonsSpatialFilter();

  RegionType FeatureBoundingRegion(const TInputImage* image, otb::ogr::Layer::const_iterator& featIt) const;

  std::string m_FieldName;

  OGRDataResampler::Pointer m_TemporaryStats;

  // Layer to use in the shape file, default to 0
  int m_LayerIndex;
};

/**
 * \class OGRDataToResampledOGRData
 * 
 * \brief Computes class statistics based on vectors using a persistent filter
 * 
 * \sa PersistentOGRDataToResampledOGRData
 */
template<class TInputImage, class TMaskImage>
class ITK_EXPORT OGRDataToResampledOGRData :
  public PersistentFilterStreamingDecorator<PersistentOGRDataToResampledOGRData<TInputImage,TMaskImage> >
{
public:
  /** Standard Self typedef */
  typedef OGRDataToResampledOGRData  Self;
  typedef PersistentFilterStreamingDecorator
    <PersistentOGRDataToResampledOGRData
      <TInputImage,TMaskImage> >          Superclass;
  typedef itk::SmartPointer<Self>         Pointer;
  typedef itk::SmartPointer<const Self>   ConstPointer;

  typedef TInputImage                     InputImageType;
  typedef TMaskImage                      MaskImageType;
  typedef otb::ogr::DataSource            OGRDataType;
  
  typedef typename Superclass::FilterType             FilterType;
  typedef typename FilterType::ClassCountMapType      ClassCountMapType;
  typedef typename FilterType::PolygonSizeMapType     PolygonSizeMapType;
  typedef typename FilterType::ClassCountObjectType   ClassCountObjectType;
  typedef typename FilterType::PolygonSizeObjectType  PolygonSizeObjectType;

  /** Type macro */
  itkNewMacro(Self);

  /** Creation through object factory macro */
  itkTypeMacro(OGRDataToResampledOGRData, PersistentFilterStreamingDecorator);

  using Superclass::SetInput;
  virtual void SetInput(const TInputImage* image);

  const TInputImage* GetInput();

  void SetOGRData(const otb::ogr::DataSource* data);
  const otb::ogr::DataSource* GetOGRData();

  void SetMask(const TMaskImage* mask);
  const TMaskImage* GetMask();

  void SetFieldName(std::string &key);
  std::string GetFieldName();
  
  void SetLayerIndex(int index);
  int GetLayerIndex();

  const ClassCountObjectType* GetClassCountOutput() const;
  ClassCountObjectType* GetClassCountOutput();

  const PolygonSizeObjectType* GetPolygonSizeOutput() const;
  PolygonSizeObjectType* GetPolygonSizeOutput();

protected:
  /** Constructor */
  OGRDataToResampledOGRData() {}
  /** Destructor */
  virtual ~OGRDataToResampledOGRData() {}

private:
  OGRDataToResampledOGRData(const Self &); //purposely not implemented
  void operator =(const Self&); //purposely not implemented
};

} // end of namespace otb

#ifndef OTB_MANUAL_INSTANTIATION
#include "otbOGRDataToResampledOGRData.txx"
#endif

#endif
