#ifndef RefTrackAlignProcessor_h
#define RefTrackAlignProcessor_h 1

#include "marlin/Processor.h"
#include "lcio.h"
#include <string>


using namespace lcio;
using namespace marlin;


/**  
 * @param CollectionName Name of the MCParticle collection
 * 
 * @author F. Gaede, DESY
 * @version $Id: RefTrackAlignProcessor.h,v 1.4 2005-10-11 12:57:39 gaede Exp $ 
 */

class RefTrackAlignProcessor : public Processor {
  
 public:
  
  virtual Processor*  newProcessor() { return new RefTrackAlignProcessor; }
  
  
  RefTrackAlignProcessor();
  
  /** Called at the begin of the job before anything is read.
   * Use to initialize the processor, e.g. book histograms.
   */
  virtual void init();
  
  /** Called for every run.
   */
  virtual void processRunHeader( LCRunHeader* run );
  
  /** Called for every event - the working horse.
   */
  virtual void processEvent( LCEvent * evt ); 
  
  
  virtual void check( LCEvent * evt ); 
  
  
  /** Called after data processing for clean up.
   */
  virtual void end();
  
  
 protected:

  /// REF tracker data collection name
  std::string _colRefData;
  /// fitted Track collection name
  std::string _colTracks;
  /// aligned REF hit collection name
  std::string _colAligned;
  /// REF alignment DB name
  std::string _refAlignDB;
};

#endif


