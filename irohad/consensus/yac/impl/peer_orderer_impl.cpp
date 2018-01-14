/**
 * Copyright Soramitsu Co., Ltd. 2017 All Rights Reserved.
 * http://soramitsu.co.jp
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *        http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "consensus/yac/impl/peer_orderer_impl.hpp"
#include <random>

namespace iroha {
  namespace consensus {
    namespace yac {

      PeerOrdererImpl::PeerOrdererImpl(
          std::shared_ptr<ametsuchi::PeerQuery> peer_query)
          : query_(std::move(peer_query)) {}

      nonstd::optional<ClusterOrdering> PeerOrdererImpl::getInitialOrdering() {
        return query_->getLedgerPeers() | [](const auto &peers) {
          return ClusterOrdering::create(peers);
        };
      }

      nonstd::optional<ClusterOrdering> PeerOrdererImpl::getOrdering(
          YacHash hash) {
        return query_->getLedgerPeers() | [&hash](auto peers){
          std::seed_seq seed(hash.block_hash.begin(),hash.block_hash.end());
          std::default_random_engine gen(seed);
          std::shuffle(peers.begin(), peers.end(), gen);
          return nonstd::make_optional<ClusterOrdering>(peers);
        };
      }
    }  // namespace yac
  }    // namespace consensus
}  // namespace iroha
