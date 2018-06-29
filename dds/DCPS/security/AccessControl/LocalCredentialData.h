/*
 * Distributed under the DDS License.
 * See: http://www.DDS.org/license.html
 */

#ifndef DDS_DCPS_ACCESS_CONTROL_LOCAL_CREDENTIAL_DATA_H
#define DDS_DCPS_ACCESS_CONTROL_LOCAL_CREDENTIAL_DATA_H

#include <string>

#include "dds/DCPS/security/SSL/Certificate.h"
#include "dds/DCPS/security/SSL/SignedDocument.h"

#include "dds/DdsDcpsCoreC.h"

namespace OpenDDS {
namespace Security {

  class LocalAccessCredentialData
  {
  public:
    LocalAccessCredentialData(const DDS::PropertySeq& props);

    LocalAccessCredentialData();

    ~LocalAccessCredentialData();

    void load(const DDS::PropertySeq& props);

    SSL::Certificate& get_ca_cert()
    {
      return *ca_cert_;
    }

    SSL::SignedDocument& get_governance_doc()
    {
      return *governance_doc_;
    }

    SSL::SignedDocument& get_permissions_doc()
    {
      return *permissions_doc_;
    }

  private:

    SSL::Certificate::unique_ptr ca_cert_;
    SSL::SignedDocument::unique_ptr governance_doc_;
    SSL::SignedDocument::unique_ptr permissions_doc_;

  };

}
}

#endif
