import { createAppKit } from '@reown/appkit/react'

import { defineChain } from '@reown/appkit/networks';

import { QueryClient, QueryClientProvider } from '@tanstack/react-query'

// 0. Setup queryClient
const queryClient = new QueryClient()

// 1. Get projectId from https://cloud.reown.com
const projectId = '8a37cd52e8de78f6bdb6b12f1e213874'


// 3. Set the networks

const localhost = defineChain({
  id: 1337,
  caipNetworkId: 'eip155:5777',
  chainNamespace: 'eip155',
  name: 'Localhost',
  nativeCurrency: {
    decimals: 18,
    name: 'Ether',
    symbol: 'ETH',
  },
  rpcUrls: {
    default: {
      http: ['HTTP://127.0.0.1:7545'],
      // webSocket: ['WS_RPC_URL'],
    },
  },
  blockExplorers: {
    default: { name: 'Explorer', url: 'BLOCK_EXPLORER_URL' },
  },
  contracts: {
    // Add the contracts here
  }
})
// 5. Create modal
createAppKit({
  networks: [localhost],
  projectId,
  features: {
    analytics: true // Optional - defaults to your Cloud configuration
  }
})
